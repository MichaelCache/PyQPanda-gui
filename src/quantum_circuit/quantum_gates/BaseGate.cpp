#include "BaseGate.h"

#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QMenu>

// GateRectF BaseGate::m_gate_rect;
GateFont BaseGate::m_gate_font;

BaseGate::BaseGate(const QString &name, const QRectF &gate_rect, QObject *parent)
    : QObject(parent),
      QGraphicsItem(),
      m_name(name.trimmed().toUpper()),
      m_gate_rect(gate_rect)
{
  setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
  initPropertyMenu();
}

BaseGate::~BaseGate() {}

void BaseGate::initPropertyMenu()
{
  QAction *dagger = m_property_menu.addAction("Dagger");
  QAction *del_gate = m_property_menu.addAction("Delete");

  QObject::connect(dagger, SIGNAL(triggered()), this, SLOT(setDagger()));
  QObject::connect(del_gate, SIGNAL(triggered()), this, SLOT(deleteSelf()));
}

void BaseGate::setDagger()
{
  m_is_dagger = !m_is_dagger;
  update();
}

void BaseGate::deleteSelf()
{
  if (scene())
  {
    scene()->removeItem(this);
  }
}

void BaseGate::isInValid(bool valid, QPointF top_left)
{
  if (valid)
  {
    m_gate_rect.moveTopLeft(top_left);
  }
  else
  {
    deleteSelf();
  }
}

QRectF BaseGate::boundingRect() const
{
  return m_gate_rect;
}

void BaseGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
  painter->fillRect(m_gate_rect, m_gate_rect);
  painter->setPen(m_gate_font);
  painter->setFont(m_gate_font);
  painter->drawText(m_gate_rect, Qt::AlignCenter, m_is_dagger ? m_name + m_dagger : m_name);
}

void BaseGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  emit showValidBox(m_gate_rect);
  QGraphicsItem::mouseMoveEvent(event);
}

// void BaseGate::mousePressEvent(QGraphicsSceneMouseEvent *event){
//   QGraphicsItem::mousePressEvent(event);
// }

void BaseGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsItem::mouseReleaseEvent(event);
  ungrabMouse();
  setSelected(false);
  emit hideValidBox();
  emit checkInValidBox(m_gate_rect);
}

void BaseGate::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
  QAction *selectedAction = m_property_menu.exec(event->screenPos());
}
