#include <QGraphicsScene>
#include <QDebug>

#include "FrameLine.h"
#include "BitFont.h"

FrameLine::FrameLine(const QString &label, const QPointF &pos, QObject *parent)
    : QObject(parent),
      QGraphicsItemGroup(),
      m_valid_pos(pos)
{

  QPointF end_pos = {500 * 0.9, 0};
  
  m_frame_line = new QGraphicsLineItem({{0,0}, end_pos}, this);
  qDebug() << QString("line pos: %1,%2").arg(m_frame_line->scenePos().x()).arg(m_frame_line->scenePos().y());
  QPen pen;
  pen.setWidth(4);
  m_frame_line->setPen(pen);

  m_line_label = new QGraphicsTextItem(label, this);
  m_line_label->setFont(BitFont(16, Qt::black));
  QPointF lable_top_left(pos.x() - m_line_label->textWidth() / 2, pos.y() - m_line_label->textWidth() / 2);
  m_line_label->setPos(lable_top_left);

  m_valid_pos += {m_step, 0};

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
  m_virtual_gate->setRect(rect);
  m_virtual_gate->setPos(m_valid_pos);
  m_virtual_gate->setVisible(true);
  update();
}

void FrameLine::hideValidPos()
{
  m_virtual_gate->setVisible(false);
  update();
}

void FrameLine::checkValidPos(QRectF rect)
{
  QRectF valid_rect(m_virtual_gate->rect());
  qDebug() << QString("ValidPos: ") + QString().number(m_virtual_gate->scenePos().x()) + ":" + QString().number(m_virtual_gate->scenePos().y());
  valid_rect.moveTopLeft(m_virtual_gate->scenePos());
  if (valid_rect.intersects(rect))
  {
    emit isInValidPos(true, m_virtual_gate->scenePos());
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
    m_valid_pos += {m_step, 0};
  }
  else
  {
    if ((m_valid_pos - QPointF(m_step, 0)).x() <= m_frame_line->x())
    {
      m_valid_pos.setX(m_frame_line->x() + m_step);
    }
    else
    {
      m_valid_pos -= {m_step, 0};
    }
  }
}