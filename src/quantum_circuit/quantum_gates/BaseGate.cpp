#include "BaseGate.h"

#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

// GateRectF BaseGate::m_gate_rect;
GateFont BaseGate::m_gate_font;

BaseGate::BaseGate(const QString &name, const QRectF& gate_rect, QObject *parent)
    : QObject(parent),
      QGraphicsItem(),
      m_name(name.trimmed().toUpper()),
      m_item(nullptr),
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

void BaseGate::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  if (m_item == nullptr)
  {
    QWidget *widget = new QWidget();
    widget->setFixedSize(QSize(300, 300));
    m_item = scene()->addWidget(widget);
    m_item->setParentItem(this);
    m_item->hide();
  }
  // pop widget while right mouse button pressed
  if (event->button() == Qt::RightButton)
  {
    m_item->setPos(
        QPointF(this->boundingRect().width(), this->boundingRect().height()));
    m_item->show();
  }
  else if (event->button() == Qt::LeftButton)
  {
    m_item->hide();
  }
  QGraphicsItem::mousePressEvent(event);
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
