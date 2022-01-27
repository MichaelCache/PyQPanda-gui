#include <QGraphicsScene>

#include "FrameLine.h"
#include "BitFont.h"

FrameLine::FrameLine(const QString &label, const QPointF &pos, QObject *parent)
    : QObject(parent),
      QGraphicsItemGroup()
{

  QPointF end_pos = {pos.x() + 500 * 0.9, pos.y()};

  m_frame_line = new QGraphicsLineItem({pos, end_pos});
  QPen pen;
  pen.setWidth(4);
  m_frame_line->setPen(pen);

  m_line_label = new QGraphicsTextItem(label);
  m_line_label->setFont(BitFont(16, Qt::black));
  QPointF lable_central(pos.x() + m_line_label->textWidth() / 2, pos.y() + m_line_label->textWidth() / 2);
  m_line_label->setPos(lable_central);

  m_valid_pos.setY(pos.y());
  m_valid_pos.setX(pos.x() + 30);

  m_virtual_gate = new QGraphicsRectItem();

  QPen gate_pen(Qt::DashLine);
  gate_pen.setBrush(Qt::gray);
  m_virtual_gate->setPen(gate_pen);

  addToGroup(m_line_label);
  addToGroup(m_frame_line);
  addToGroup(m_virtual_gate);
}

FrameLine::~FrameLine()
{
}

void FrameLine::showValidPos(QRectF rect)
{
  rect.moveCenter(m_valid_pos);
  m_virtual_gate->setRect(rect);
  // m_virtual_gate->setPos(m_valid_pos);
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
  if (m_virtual_gate->rect().intersects(rect))
  {
    emit inValidPos(true, m_virtual_gate->rect().topLeft());
  }
  else
  {
    emit inValidPos(false, {0, 0});
  }
}