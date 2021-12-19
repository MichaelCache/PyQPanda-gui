#include "CircuitScene.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>

CircuitScene::CircuitScene(QWidget *parent) : QGraphicsScene(parent)
{
  m_gate_factory = new GateFactory("H", 300, 400, this);
  addItem(m_gate_factory);
}

CircuitScene::~CircuitScene() {}

