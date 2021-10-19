#include <QPainter>

#include "GateFactory.h"

GateFactory::GateFactory(const QString &gate, QObject *parent)
    : QObject(parent),
      QGraphicsItem(),
      m_gate_type(gate.trimmed().toLower())
{
  m_gate_img.load(QString(":%1gate.png").arg(m_gate_type));
}

GateFactory::~GateFactory() {}

BaseGate *createGate()
{
}

QRectF GateFactory::boundingRect() const
{
  return QRectF(0, 0, m_gate_img.width(), m_gate_img.height());
}

void GateFactory::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->drawPixmap(boundingRect().topLeft(), m_gate_img);
}