#include <QGraphicsScene>
#include <QDebug>

#include "CircuitLine.h"
#include "BitFont.h"

FrameLine::FrameLine(const QString &label, const QPointF &pos, QObject *parent)
    : QObject(),
      QGraphicsItemGroup()
{
  QGraphicsItemGroup::setPos(pos);

  QPointF end_pos = {500 * 0.9, 0};

  m_frame_line = new QGraphicsLineItem({{0, 0}, end_pos}, this);
  QPen pen;
  pen.setWidth(4);
  m_frame_line->setPen(pen);

  m_line_label = new QGraphicsTextItem(label, this);
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

FrameLine::~FrameLine()
{
}

void FrameLine::showValidPos(QRectF rect)
{
  m_virtual_gate->setRect(0, 0, rect.width(), rect.height());
  m_virtual_gate->setPos(m_valid_pos.x(), m_valid_pos.y() - rect.height() / 2);
  m_virtual_gate->setVisible(true);
  update();
}

void FrameLine::hideValidPos()
{
  m_virtual_gate->setVisible(false);
  update();
}

void FrameLine::checkValidPos(QRectF rect, BaseGate *g)
{
  QRectF valid_rect = mapRectToScene(m_virtual_gate->rect());
  valid_rect.moveTopLeft(m_virtual_gate->scenePos());
  qDebug() << QString("valid_rect: %1, %2").arg(valid_rect.x()).arg(valid_rect.y());
  // valid_rect.moveTopLeft(m_virtual_gate->scenePos());
  if (valid_rect.intersects(rect))
  {
    emit isInValidPos(true, valid_rect.topLeft());
  }
  else
  {
    emit isInValidPos(false, {0, 0});
  }
}

void FrameLine::occupyPos(bool is_occupied)
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