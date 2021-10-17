#include <QPainter>

#include "BaseGate.h"

QuantumGate::QuantumGate(QObject *parent) : QObject(parent), QGraphicsItem()
{
    // m_gate_img.load(":gate.png");
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);
}

QuantumGate::~QuantumGate() {}

QRectF QuantumGate::boundingRect() const
{
    return QRectF(0, 0, m_gate_img.width(), m_gate_img.height());
}

// void QuantumGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
// {
// painter->drawPixmap(boundingRect().topLeft(), m_gate_img);
// }

// void QuantumGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
// {
// }
// void QuantumGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
// {
// }