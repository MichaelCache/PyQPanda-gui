#include "GateFactory.h"

#include <QDebug>
#include <QPainter>

GateFactory::GateFactory(const QString &gate, QObject *parent)
    : QObject(parent),
      QGraphicsItem(),
      m_gate_type(gate.trimmed().toUpper()),
      m_scence(dynamic_cast<CircuitScene *>(parent)) {
  m_gate_img.load(QString(":%1gate.png").arg(m_gate_type));
  setFlags(QGraphicsItem::ItemIsSelectable);
  setAcceptHoverEvents(true);
}

GateFactory::~GateFactory() {}

BaseGate *createGate() {}

QRectF GateFactory::boundingRect() const {
  //  mapToScene(0,0);
  return QRectF(0, 0, m_gate_img.width(), m_gate_img.height());
}

void GateFactory::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option,
                        QWidget *widget) {
  painter->drawPixmap(boundingRect().topLeft(), m_gate_img);
}

void GateFactory::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  BaseGate *gate = new BaseGate("T");
  //  QGraphicsItem::mousePressEvent(event);
  m_scence->addItem(gate);
  ungrabMouse();
  gate->grabMouse();
}
// void GateFactory::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
//  // qDebug() << "move\n";
//  QGraphicsItem::mouseMoveEvent(event);
//}
// void GateFactory::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
//  qDebug() << "release\n";
//  //  ungrabMouse();
//  QGraphicsItem::mouseReleaseEvent(event);
//}
