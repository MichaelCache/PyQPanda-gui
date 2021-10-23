#include "BaseGate.h"

#include <QDebug>
#include <QPainter>

BaseGate::BaseGate(const QString &name, QObject *parent)
    : QObject(parent), QGraphicsItem(), m_name(name.trimmed().toUpper()) {
  m_gate_img.load(QString(":%1gate.png").arg(m_name));
  setFlags(QGraphicsItem::ItemIsSelectable |
           QGraphicsItem::ItemIsMovable);  // |
                                           //  QGraphicsItem::ItemIsFocusable);
}

BaseGate::~BaseGate() {}

QRectF BaseGate::boundingRect() const {
  return QRectF(0, 0, m_gate_img.width(), m_gate_img.height());
}

void BaseGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) {
  painter->drawPixmap(0, 0, m_gate_img);
}

// void BaseGate::mousePressEvent(QGraphicsSceneMouseEvent *event) {
//  QGraphicsItem::mousePressEvent(event);
//}

// void BaseGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
//  QGraphicsItem::mouseMoveEvent(event);
//}

void BaseGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsItem::mouseReleaseEvent(event);
  ungrabMouse();
  setSelected(false);
}
