#include <QGraphicsScene>

#include "FrameLine.h"
#include "BitFont.h"

FrameLine::FrameLine(const QString &label, const QPointF &pos, QObject *parent)
    : QObject(parent),
      QGraphicsItemGroup(),
      m_line_label(new QGraphicsTextItem(label))

{

  QPointF end_pos = {pos.x() + 500 * 0.9, pos.y()};

  m_frame_line = new QGraphicsLineItem({pos, end_pos});
  QPen pen;
  pen.setWidth(4);
  m_frame_line->setPen(pen);
  m_line_label->setFont(BitFont(16, Qt::black));
  QPointF lable_central(pos.x()+m_line_label->textWidth()/2, pos.y()+m_line_label->textWidth()/2);
  m_line_label->setPos(lable_central);
  addToGroup(m_line_label);
  addToGroup(m_frame_line);
}

FrameLine::~FrameLine()
{
}
