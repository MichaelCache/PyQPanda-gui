#include "Circuit.h"

Circuit::Circuit(const QPointF &pos, QObject *parent)
    : QObject(parent),
      QGraphicsItem()
{
  QGraphicsItem::setPos(pos);
  for (size_t i = 0; i < m_init_lines; i++)
  {
    pushFrameLine();
  }
}

QRectF Circuit::boundingRect() const
{
  return QRectF(0, 0, 200, 300);
}

void Circuit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void Circuit::pushFrameLine()
{
  if (m_circ_lines.empty())
  {
    m_circ_lines.push_back(new CircuitLine("q_0", {0, 0}, this));
  }
  else
  {
    auto pos = m_circ_lines.back()->pos() + QPointF(0, m_circ_interval);
    QString line_name = QString("q_%1").arg(m_circ_lines.size());
    m_circ_lines.push_back(new CircuitLine(line_name, pos, this));
  }
  m_circ_lines.back()->setParentItem(this);
  // addToGroup(m_circ_lines.back());
}

void Circuit::popFrameLine()
{
  if (!m_circ_lines.empty())
  {
    // m_circ_lines.back()->setParentItem(nullptr);
    delete m_circ_lines.back();
    // removeFromGroup(m_circ_lines.back());
    m_circ_lines.pop_back();
  }
}

void Circuit::addGate(BaseGate *gate)
{
  gate->setParentItem(this);
  tryAddGate(gate);
  // addToGroup(gate);
  m_gates.append(gate);
}

void Circuit::tryAddGate(BaseGate *gate)
{
  for (auto frame_line : m_circ_lines)
  {
    connect(gate, SIGNAL(showValidPos(QRectF)), frame_line, SLOT(showValidPos(QRectF)));
    // connect(gate, SIGNAL(hideValidPos()), frame_line, SLOT(hideValidPos()));
    // connect(gate, SIGNAL(occupyPos(bool)), frame_line, SLOT(occupyPos(bool)));
  }
  // connect(gate, SIGNAL(connectDelete(BaseGate *)), this, SLOT(temporaryConnectDelete(BaseGate *)));
  // connect(gate, SIGNAL(disconnectDelete(BaseGate *)), this, SLOT(temporaryDisConnectDelete(BaseGate *)));
  // connect(gate, SIGNAL(deleteGate(QGraphicsItem *)), this, SLOT(deleteItem(QGraphicsItem *)));
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