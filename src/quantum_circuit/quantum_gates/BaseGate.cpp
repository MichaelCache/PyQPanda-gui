#include <QPainter>

#include "BaseGate.h"

BaseGate::BaseGate(const QString &name, QObject *parent)
    : QObject(parent),
      QGraphicsItem(),
      m_name(name.toUpper())
{
    QString pic_res = ":" + m_name + "gate.png";
    m_gate_img.load(pic_res);
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);
}

BaseGate::~BaseGate() {}

QRectF BaseGate::boundingRect() const
{
    return QRectF(0, 0, m_gate_img.width(), m_gate_img.height());
}

// void BaseGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
// {
// painter->drawPixmap(boundingRect().topLeft(), m_gate_img);
// }

// void BaseGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
// {
// }
// void BaseGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
// {
// }