#include "BaseGate.h"

#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QMenu>
#include "../Circuit.h"

GateFont BaseGate::m_gate_font;

BaseGate::BaseGate(const QString &name, const QPointF &pos, const QRectF &gate_rect, QGraphicsItem *parent)
    : QGraphicsObject(parent),
      m_name(name.trimmed().toUpper()),
      m_gate_rect(gate_rect)
{
  setPos(pos);
  setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
  initPropertyMenu();
}

BaseGate::~BaseGate() {}

void BaseGate::initPropertyMenu()
{
  QAction *dagger = m_property_menu.addAction("Dagger");
  QAction *del_gate = m_property_menu.addAction("Delete");

  QObject::connect(dagger, SIGNAL(triggered()), this, SLOT(setDagger()));
  QObject::connect(del_gate, SIGNAL(triggered()), this, SLOT(deleteSelf()));
}

void BaseGate::setDagger()
{
  m_is_dagger = !m_is_dagger;
  update();
}

void BaseGate::deleteSelf()
{
  emit deleteGate(this);
}

// void BaseGate::isInValidPos(bool valid, QPointF scene_pos)
// {
//   QPointF this_scene_pos = scenePos();
//   qDebug() << QString("this pos: %1, %2").arg(this_scene_pos.x()).arg(this_scene_pos.y());
//   if (valid)
//   {
//     qDebug() << QString("scene pos: %1, %2").arg(scene_pos.x()).arg(scene_pos.y());

//     QPointF rela_pos = scene_pos + this_scene_pos;
//     qDebug() << QString("scene pos map to item pos: %1, %2").arg(mapFromScene(scene_pos).x()).arg(mapFromScene(scene_pos).y());

//     setPos(scene_pos);
//     update();
//     emit occupyPos(true);
//     m_in_valid = true;
//   }
//   else
//   {
//     emit occupyPos(false);
//     m_in_valid = false;
//   }
// }

QRectF BaseGate::boundingRect() const
{
  return m_gate_rect;
}

void BaseGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
  painter->fillRect(m_gate_rect, m_gate_rect);
  painter->setPen(m_gate_font);
  painter->setFont(m_gate_font);
  painter->drawText(m_gate_rect, Qt::AlignCenter, m_is_dagger ? m_name + m_dagger : m_name);
}

void BaseGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  emit showValidPos(this);
  QGraphicsItem::mouseMoveEvent(event);
}

// void BaseGate::mousePressEvent(QGraphicsSceneMouseEvent *event){
//   QGraphicsItem::mousePressEvent(event);
// }

void BaseGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsItem::mouseReleaseEvent(event);
  ungrabMouse();
  setSelected(false);
  emit hideValidPos();

  // QRectF cur_rect = mapRectToScene(m_gate_rect);
  // emit connectDelete(this);
  // emit checkValidPos(cur_rect, this);
  // emit disconnectDelete(this);
  // if (!m_in_valid)
  // {
  //   emit deleteGate(this);
  // }
}

const GateRectF& BaseGate::gateBox() const{
  return m_gate_rect;
}

void BaseGate::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
  QAction *selectedAction = m_property_menu.exec(event->screenPos());
}
