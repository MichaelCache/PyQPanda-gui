#include "CircuitScene.h"

#include <QGraphicsSceneMouseEvent>

CircuitScene::CircuitScene(QWidget *parent)
    : QGraphicsScene(parent),
      m_gate_factory(new GateFactory("H", 300, 400, this))
{
  addItem(m_gate_factory);
  addFrameLine(new FrameLine("q_0", {30, 30}, this));
}

CircuitScene::~CircuitScene() {}

void CircuitScene::addGate(BaseGate *gate)
{
  // m_gate_group.insert(gate);
  addItem(gate);
  for (auto frame_line : m_frame_line_group)
  {
    connect(gate, SIGNAL(showValidBox(QRectF)), frame_line, SLOT(showValidPos(QRectF)));
    connect(gate, SIGNAL(hideValidBox()), frame_line, SLOT(hideValidPos()));
    connect(gate, SIGNAL(checkInValidBox(QRectF)), frame_line, SLOT(checkValidPos(QRectF)));
    connect(frame_line, SIGNAL(inValidPos(bool, QPointF)), gate, SLOT(isInValid(bool, QPointF)));
  }
  
}

void CircuitScene::addFrameLine(FrameLine *line)
{
  m_frame_line_group.insert(line);
  addItem(line);
}