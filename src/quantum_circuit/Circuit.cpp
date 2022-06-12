#include "Circuit.h"
#include <QGraphicsScene>
#include <QDebug>

Circuit::Circuit(const QPointF &pos, QObject *parent)
    : QObject(parent),
      QGraphicsItem(),
      m_circ("root", 0, m_init_lines - 1)
{
  QGraphicsItem::setPos(pos);
  for (size_t i = 0; i < m_init_lines; i++)
  {
    pushCircLine();
  }
}

QRectF Circuit::boundingRect() const
{
  return QRectF(0, 0, 200, 300);
}

void Circuit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void Circuit::pushCircLine()
{
  if (m_circ_lines.empty())
  {
    m_circ_lines.push_back(new CircuitLine("q_0", {0, 0}, this));
  }
  else
  {
    auto pos = m_circ_lines.back()->pos() + QPointF(0, m_circline_interval);
    QString line_name = QString("q_%1").arg(m_circ_lines.size());
    m_circ_lines.push_back(new CircuitLine(line_name, pos, this));
  }
  m_circ_lines.back()->setParentItem(this);
}

void Circuit::popCircLine()
{
  if (!m_circ_lines.empty())
  {
    delete m_circ_lines.back();
    m_circ_lines.pop_back();
  }
}

void Circuit::addGate(BaseGate *gate)
{
  gate->setParentItem(this);
  connectGate(gate);
  m_gates.insert(gate);
}

void Circuit::deleteGate(BaseGate *gate)
{
  auto it = m_gates.find(gate);
  if (it != m_gates.end())
  {
    this->scene()->removeItem(gate);
    m_gates.erase(it);
  }
}

void Circuit::showValidGatePosBox(BaseGate *gate)
{
  // get nearest circuit line
  auto center_y = gate->pos().y();
  double min_dis = DBL_MAX;
  int min_idx = -1;
  for (size_t i = 0; i < m_circ_lines.size(); i++)
  {
    auto line_y = mapToScene(m_circ_lines.at(i)->pos()).y();
    auto dis = std::abs(line_y - center_y);
    if (dis < min_dis)
    {
      min_dis = dis;
      min_idx = i;
    }
  }

  // let nearest circuit line show valid gate position
  for (size_t i = 0; i < m_circ_lines.size(); i++)
  {
    if (i == min_idx)
    {
      m_circ_lines.at(i)->showValidPos(gate->gateBox());
    }
    else
    {
      m_circ_lines.at(i)->hideValidPos();
    }
  }
}

void Circuit::hideValidGatePosBox()
{
  for (auto &line : m_circ_lines)
  {
    line->hideValidPos();
  }
}

void Circuit::connectGate(BaseGate *gate)
{
  for (auto circ_line : m_circ_lines)
  {
    connect(gate, SIGNAL(showValidPos(BaseGate *)), this, SLOT(showValidGatePosBox(BaseGate *)));
    connect(gate, SIGNAL(hideValidPos()), this, SLOT(hideValidGatePosBox()));
    // connect(gate, SIGNAL(occupyPos(bool)), frame_line, SLOT(occupyPos(bool)));
  }
  // connect(gate, SIGNAL(connectDelete(BaseGate *)), this, SLOT(temporaryConnectDelete(BaseGate *)));
  // connect(gate, SIGNAL(disconnectDelete(BaseGate *)), this, SLOT(temporaryDisConnectDelete(BaseGate *)));
  connect(gate, SIGNAL(deleteGate(BaseGate *)), this, SLOT(deleteGate(BaseGate *)));
}

// void Circuit::mousePressEvent(QGraphicsSceneMouseEvent *event)
// {
//   // for (auto g:m_gates)
//   // {
//   //   g->mousePressEvent(event);
//   // }
//   QGraphicsItem::mousePressEvent(event);
// }
// void Circuit::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {}
// void Circuit::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {}