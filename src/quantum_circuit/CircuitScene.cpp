#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QDebug>

#include "CircuitScene.h"
#include "../logger/Logger.h"

CircuitScene::CircuitScene(QObject *parent)
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
    connect(gate, SIGNAL(occupyPos(bool)), frame_line, SLOT(occupyPos(bool)));
  }
  connect(gate, SIGNAL(connectDelete(BaseGate *)), this, SLOT(temporaryConnectDelete(BaseGate *)));
  connect(gate, SIGNAL(disconnectDelete(BaseGate *)), this, SLOT(temporaryDisConnectDelete(BaseGate *)));
  connect(gate, SIGNAL(deleteGate(QGraphicsItem *)), this, SLOT(deleteItem(QGraphicsItem *)));
}

void CircuitScene::deleteItem(QGraphicsItem *it)
{
  removeItem(it);
}
void CircuitScene::temporaryConnectDelete(BaseGate *gate)
{
  for (auto frame_line : m_frame_line_group)
  {
    connect(gate, SIGNAL(checkValidPos(QRectF, BaseGate *)), frame_line, SLOT(checkValidPos(QRectF, BaseGate *)));
    connect(frame_line, SIGNAL(isInValidPos(bool, QPointF)), gate, SLOT(isInValidPos(bool, QPointF)));
  }
}

void CircuitScene::temporaryDisConnectDelete(BaseGate *gate)
{
  for (auto frame_line : m_frame_line_group)
  {
    disconnect(gate, SIGNAL(checkValidPos(QRectF, BaseGate *)), frame_line, SLOT(checkValidPos(QRectF, BaseGate *)));
    disconnect(frame_line, SIGNAL(isInValidPos(bool, QPointF)), gate, SLOT(isInValidPos(bool, QPointF)));
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
    SingletonLogger::instance()->append(QString("Mouse at %1:%2").arg(event->scenePos().x()).arg(event->scenePos().y()));
  }
  QGraphicsScene::mousePressEvent(event);
}