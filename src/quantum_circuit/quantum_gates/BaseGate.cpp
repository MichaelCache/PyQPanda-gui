#include "BaseGate.h"

#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

BaseGate::BaseGate(const QString &name, QObject *parent)
    : QObject(parent),
      QGraphicsItem(),
      m_name(name.trimmed().toUpper()),
      m_item(nullptr) {
  m_gate_img.load(QString(":%1gate.png").arg(m_name));
  setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

BaseGate::~BaseGate() {}

QRectF BaseGate::boundingRect() const {
  return QRectF(0, 0, m_gate_img.width(), m_gate_img.height());
}

void BaseGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) {
  painter->drawPixmap(0, 0, m_gate_img);
}

void BaseGate::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  if (m_item == nullptr) {
    QWidget *widget = new QWidget();
    widget->setFixedSize(QSize(300, 300));
    m_item = scene()->addWidget(widget);
    m_item->setParentItem(this);
    m_item->hide();
  }
  // pop widget while right mouse button pressed
  if (event->button() == Qt::RightButton) {
    m_item->setPos(
        QPointF(this->boundingRect().width(), this->boundingRect().height()));
    m_item->show();
  } else if (event->button() == Qt::LeftButton) {
    m_item->hide();
  }
  QGraphicsItem::mousePressEvent(event);
}

void BaseGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsItem::mouseMoveEvent(event);
}

void BaseGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsItem::mouseReleaseEvent(event);
  ungrabMouse();
  setSelected(false);
}
