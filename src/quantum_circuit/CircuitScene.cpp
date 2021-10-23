#include "CircuitScene.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>

CircuitScene::CircuitScene(QWidget *parent) : QGraphicsScene(parent) {
  // m_gate = new BaseGate(this);
  m_gate_factory = new GateFactory("H", this);
  addItem(m_gate_factory);
}

CircuitScene::~CircuitScene() {}

// void CircuitScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) {
//  QGraphicsScene::mouseMoveEvent(mouseEvent);
//}
