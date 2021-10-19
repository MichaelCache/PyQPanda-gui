#ifndef CIRCUITASSEMBLEWIDGET_H
#define CIRCUITASSEMBLEWIDGET_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QWidget>

#include "quantum_gates/BaseGate.h"
#include "quantum_gates/GateFactory.h"

class CircuitScence : public QGraphicsScene
{
  Q_OBJECT
public:
  explicit CircuitScence(QWidget *parent = nullptr);
  virtual ~CircuitScence();

signals:

private:
  // BaseGate *m_gate;
  GateFactory *m_gate_factory;
  // QList < BaseFa
};

#endif // CIRCUITASSEMBLEWIDGET_H
