#include "GateFactory.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

GateFont GateFactory::m_gate_font;

GateFactory::GateFactory(const QString &gate, qreal x, qreal y, QObject *parent)
    : QObject(),
      QGraphicsItem(),
      m_gate_type(gate.trimmed().toUpper())
{
  setPos(x, y);
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
  // drag action to create a new gate rectanguler block from gate factory rectanguler block to GraphicScene
  if (event->button() == Qt::LeftButton)
  {
    BaseGate *gate = new BaseGate(m_gate_type, scenePos(), m_gate_rect);
    static_cast<CircuitScene *>(scene())->addGate(gate);
    QGraphicsItem::mousePressEvent(event);
    // gate get mouse fouce, gate factory lose mouse
    ungrabMouse();
    gate->grabMouse();
  }
}
