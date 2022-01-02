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
}

BaseGate::~BaseGate() {}

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
  painter->drawText(m_gate_rect, Qt::AlignCenter, m_name);
}

void BaseGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsItem::mouseMoveEvent(event);
}

void BaseGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsItem::mouseReleaseEvent(event);
  ungrabMouse();
  setSelected(false);
}

void BaseGate::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
  QMenu menu;
  QAction *dagger_gate = menu.addAction("Dagger");
  QAction *delete_gate = menu.addAction("Delete");
  QAction *selectedAction = menu.exec(event->screenPos());
}
