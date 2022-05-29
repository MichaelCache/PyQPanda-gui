#pragma once

#include <QGraphicsRectItem>
#include <QString>
#include <QWidget>

#include "CircuitScene.h"
#include "quantum_gates/BaseGate.h"
#include "quantum_gates/GateRectF.h"
#include "quantum_gates/GateFont.h"

class CircuitScene;

/**
 * @brief automatic generate BaseGate
 */
class GateFactory : public QObject, public QGraphicsItem
{
public:
  explicit GateFactory(const QString &gate, qreal x, qreal y, QObject *parent = nullptr);
  virtual ~GateFactory();
  QRectF boundingRect() const;

protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

  QString m_gate_type; // gate factory name or gate type factory name
  GateRectF m_gate_rect;
  static GateFont m_gate_font;
};
