#pragma once

#include <QGraphicsRectItem>
#include <QString>
#include <QWidget>

#include "../CircuitScene.h"
#include "BaseGate.h"

class CircuitScene;

class GateFactory : public QObject, public QGraphicsItem {
 public:
  explicit GateFactory(const QString &gate, QObject *parent = nullptr);
  virtual ~GateFactory();
  QRectF boundingRect() const;
  BaseGate *createGate();

 protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  //  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
  //  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
  // void hoverEn

  QString m_gate_type;
  QPixmap m_gate_img;
  CircuitScene *m_scence;
};
