#include "CircuitScene.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>

CircuitScene::CircuitScene(QWidget *parent)
    : QGraphicsScene(parent),
      m_gate_factory(new GateFactory("H", 300, 400, this)),
      m_frame_line(new FrameLine("q_0", {30, 30}, this))
{
  addItem(m_gate_factory);
  addItem(m_frame_line);
}

CircuitScene::~CircuitScene() {}
