#ifndef CIRCUITASSEMBLEWIDGET_H
#define CIRCUITASSEMBLEWIDGET_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QWidget>

#include "quantum_gates/BaseGate.h"
#include "quantum_gates/GateFactory.h"

class GateFactory;

class CircuitScene : public QGraphicsScene {
  Q_OBJECT
 public:
  explicit CircuitScene(QWidget *parent = nullptr);
  virtual ~CircuitScene();

 signals:
 protected:
  //  void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);

 private:
  // BaseGate *m_gate;
  GateFactory *m_gate_factory;
  // QList < BaseFa
};

#endif  // CIRCUITASSEMBLEWIDGET_H
