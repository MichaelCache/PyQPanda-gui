#include <QGraphicsScene>
#include <QDebug>
#include <cmath>

#include "CircuitLine.h"
#include "BitFont.h"
namespace
{
  double distance(QPointF a, QPointF b)
  {
    double dx = a.x() - b.x();
    double dy = a.y() - b.y();
    return std::sqrt(dx * dx + dy * dy);
  }

} // namespace

CircuitLine::CircuitLine(const QString &label, uint64_t row, const QPointF &pos, QObject *parent)
    : QObject(),
      QGraphicsItemGroup(),
      m_row(row)
{
  QGraphicsItemGroup::setPos(pos);

  QPointF end_pos = {500 * 0.9, 0};

  m_frame_line = new QGraphicsLineItem({{0, 0}, end_pos}, this);
  QPen pen;
  pen.setWidth(4);
  m_frame_line->setPen(pen);

  QString line_name = QString("%1_%2").arg(label).arg(row);
  m_line_label = new QGraphicsTextItem(line_name, this);
  m_line_label->setFont(BitFont(16, Qt::black));
  qreal label_line_gap = 10;
  QPointF lable_top_left(0 - label_line_gap - m_line_label->boundingRect().width(), 0 - m_line_label->boundingRect().height() / 2);
  m_line_label->setPos(lable_top_left);

  m_virtual_gate = new QGraphicsRectItem(this);

  QPen gate_pen(Qt::DashLine);
  gate_pen.setBrush(Qt::gray);
  m_virtual_gate->setPen(gate_pen);
  m_virtual_gate->setPos(m_valid_pos);

  addToGroup(m_line_label);
  addToGroup(m_frame_line);
  addToGroup(m_virtual_gate);
}

CircuitLine::~CircuitLine()
{
}

void CircuitLine::showValidPos(const QRectF &rect)
{
  m_virtual_gate->setRect(0, 0, rect.width(), rect.height());
  m_virtual_gate->setPos(m_valid_pos.x(), m_valid_pos.y() - rect.height() / 2);
  m_virtual_gate->setVisible(true);
  update();
}

void CircuitLine::hideValidPos()
{
  m_virtual_gate->setVisible(false);
  update();
}

void CircuitLine::checkValidPos(BaseGate *g)
{
  QRectF rect = g->mapRectToScene(g->gateBox());
  QRectF valid_rect = g->mapRectToScene(m_virtual_gate->rect());
  valid_rect.moveTopLeft(m_virtual_gate->scenePos());
  qDebug() << QString("valid_rect: %1, %2").arg(valid_rect.x()).arg(valid_rect.y());
  if (valid_rect.intersects(rect))
  {
    g->setPos(valid_rect.x(), valid_rect.y());
    emit isInValidPos(g, m_row, 1);
  }
  else
  {
    emit notInValidPos(g);
  }
}

void CircuitLine::occupyPos(bool is_occupied)
{
  if (is_occupied)
  {
    m_valid_pos += {2 * m_step, 0};
  }
  else
  {
    if ((m_valid_pos - QPointF(m_step, 0)).x() <= m_frame_line->x())
    {
      m_valid_pos.setX(m_frame_line->x() + m_step);
    }
    else
    {
      m_valid_pos -= {2 * m_step, 0};
    }
  }
}