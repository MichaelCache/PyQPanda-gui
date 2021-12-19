#include "GateFactory.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

// GateRectF GateFactory::m_gate_rect(0, 0);
GateFont GateFactory::m_gate_font;

GateFactory::GateFactory(const QString &gate, qreal x, qreal y, QObject *parent)
    : QObject(parent),
      QGraphicsItem(),
      m_gate_type(gate.trimmed().toUpper()),
      m_gate_rect(x, y)
{
  setFlags(QGraphicsItem::ItemIsSelectable);
  setAcceptHoverEvents(true);
}

GateFactory::~GateFactory() {}

QRectF GateFactory::boundingRect() const
{
  return m_gate_rect;
}

void GateFactory::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option,
                        QWidget *widget)
{
  painter->fillRect(m_gate_rect, m_gate_rect);
  painter->setPen(m_gate_font);
  painter->setFont(m_gate_font);
  painter->drawText(m_gate_rect, Qt::AlignCenter, m_gate_type);
}

void GateFactory::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
  {
    BaseGate *gate = new BaseGate(m_gate_type, m_gate_rect);
    scene()->addItem(gate);
    QGraphicsItem::mousePressEvent(event);
    ungrabMouse();
    gate->grabMouse();
  }
}
