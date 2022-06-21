#include "Circuit.h"
#include <QGraphicsScene>
#include <QDebug>
#include <cfloat>

Circuit::Circuit(const QPointF &pos, QGraphicsItem *parent)
    : QGraphicsObject(parent),
      m_circ("root", m_init_lines),
      m_nearest_line_idx(-1)
{
  QGraphicsItem::setPos(pos);
  for (size_t i = 0; i < m_init_lines; i++)
  {
    pushCircLine(i);
  }
}

QRectF Circuit::boundingRect() const
{
  return QRectF(0, 0, 200, 300);
}

void Circuit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void Circuit::pushCircLine(uint64_t row_num)
{
  QPointF pos{0, 0};
  if (!m_circ_lines.isEmpty())
  {
    pos = m_circ_lines.back()->pos() + QPointF(0, m_circline_interval);
  }

  m_circ_lines.push_back(new CircuitLine("q", row_num, pos, this));
  m_circ_lines.back()->setParentItem(this);
  connect(m_circ_lines.back(), SIGNAL(isInValidPos(BaseGate *, uint64_t, uint64_t)), this, SLOT(addGate(BaseGate *, uint64_t, uint64_t)));
  connect(m_circ_lines.back(), SIGNAL(notInValidPos(BaseGate *)), this, SLOT(deleteGate(BaseGate *)));
}

void Circuit::popCircLine()
{
  if (!m_circ_lines.empty())
  {
    delete m_circ_lines.back();
    m_circ_lines.pop_back();
  }
}

void Circuit::tryAddGate(BaseGate *gate)
{
  gate->setParentItem(this);
  connectGate(gate);
}

void Circuit::addGate(BaseGate *gate, uint64_t row, uint64_t col)
{
  m_gates.insert(gate);
  m_circ.insert(gate->circ(), row, col);
}

void Circuit::deleteGate(BaseGate *gate)
{
  auto it = m_gates.find(gate);
  if (it != m_gates.end())
  {
    m_gates.erase(it);
  }
  m_circ.deleteGate(gate->circ());
  this->scene()->removeItem(gate);
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
      m_nearest_line_idx = i;
    }
    else
    {
      m_circ_lines.at(i)->hideValidPos();
      m_nearest_line_idx = i;
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

void Circuit::checkValidPos(BaseGate *gate)
{
  auto neaerst_line = m_circ_lines.at(m_nearest_line_idx);
  neaerst_line->checkValidPos(gate);
}

void Circuit::connectGate(BaseGate *gate)
{
  connect(gate, SIGNAL(showValidPos(BaseGate *)), this, SLOT(showValidGatePosBox(BaseGate *)));
  connect(gate, SIGNAL(hideValidPos()), this, SLOT(hideValidGatePosBox()));
  connect(gate, SIGNAL(checkValidPos(BaseGate *)), this, SLOT(checkValidPos(BaseGate *)));
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