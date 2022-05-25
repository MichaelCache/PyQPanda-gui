#include "Circuit.h"

Circuit::Circuit(const QPointF &pos, QObject *parent)
    : QObject(parent),
      QGraphicsItemGroup()
{
  QGraphicsItemGroup::setPos(pos);
  for (size_t i = 0; i < m_init_lines; i++)
  {
    pushFrameLine();
  }
}

void Circuit::pushFrameLine()
{
  if (m_circ_lines.empty())
  {
    m_circ_lines.push_back(new FrameLine("q_0", {0, 0}, this));
  }
  else
  {
    auto pos = m_circ_lines.back()->pos() + QPointF(0, m_circ_interval);
    QString line_name = QString("q_%1").arg(m_circ_lines.size());
    m_circ_lines.push_back(new FrameLine(line_name, pos, this));
  }
  addToGroup(m_circ_lines.back());
}

void Circuit::popFrameLine()
{
  if (!m_circ_lines.empty())
  {
    removeFromGroup(m_circ_lines.back());
    m_circ_lines.pop_back();
  }
}