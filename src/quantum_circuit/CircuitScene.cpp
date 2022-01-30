#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

#include "CircuitScene.h"
#include "../logger/Logger.h"

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
    connect(gate, SIGNAL(showValidPos(QRectF)), frame_line, SLOT(showValidPos(QRectF)));
    connect(gate, SIGNAL(hideValidPos()), frame_line, SLOT(hideValidPos()));
    connect(gate, SIGNAL(checkValidPos(QRectF)), frame_line, SLOT(checkValidPos(QRectF)));
    connect(frame_line, SIGNAL(isInValidPos(bool, QPointF)), gate, SLOT(isInValidPos(bool, QPointF)));
    connect(gate, SIGNAL(occupyPos(bool)), frame_line, SLOT(occupyPos(bool)));
  }
}

void CircuitScene::addFrameLine(FrameLine *line)
{
  m_frame_line_group.insert(line);
  addItem(line);
}

void CircuitScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
  {
    SingletonLogger::instance()->append(QString("Mouse at %1:%2").arg(event->pos().x()).arg(event->pos().y()));
  }
  QGraphicsScene::mousePressEvent(event);
}