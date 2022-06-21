#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QDebug>
#include <memory>

#include "CircuitScene.h"
#include "Circuit.h"

CircuitScene::CircuitScene(QObject *parent)
    : QGraphicsScene(parent),
      m_circ(new Circuit({0, 0})),
      m_gate_factory(new GateFactory("H", 300, 400, this))
{
  addItem(m_circ);
  addItem(m_gate_factory);
}

CircuitScene::~CircuitScene() {}

void CircuitScene::addGate(BaseGate *gate)
{
  m_circ->tryAddGate(gate);
}

// void CircuitScene::deleteItem(QGraphicsItem *it)
// {
//   removeItem(it);
// }

// void CircuitScene::temporaryConnectDelete(BaseGate *gate)
// {
//   // for (auto frame_line : m_frame_line_group)
//   // {
//   //   connect(gate, SIGNAL(checkValidPos(QRectF, BaseGate *)), frame_line, SLOT(checkValidPos(QRectF, BaseGate *)));
//   //   connect(frame_line, SIGNAL(isInValidPos(bool, QPointF)), gate, SLOT(isInValidPos(bool, QPointF)));
//   // }
// }

// void CircuitScene::temporaryDisConnectDelete(BaseGate *gate)
// {
//   // for (auto frame_line : m_frame_line_group)
//   // {
//   //   disconnect(gate, SIGNAL(checkValidPos(QRectF, BaseGate *)), frame_line, SLOT(checkValidPos(QRectF, BaseGate *)));
//   //   disconnect(frame_line, SIGNAL(isInValidPos(bool, QPointF)), gate, SLOT(isInValidPos(bool, QPointF)));
//   // }
// }

// void CircuitScene::addFrameLine(CircuitLine *line)
// {
//   // m_frame_line_group.insert(line);
//   // addItem(line);
// }

void CircuitScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
  {
    qDebug() << "Mouse at " << event->scenePos().x() << ":" << event->scenePos().y();
  }
  QGraphicsScene::mousePressEvent(event);
}