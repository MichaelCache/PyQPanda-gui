#ifndef CIRCUITASSEMBLEWIDGET_H
#define CIRCUITASSEMBLEWIDGET_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QWidget>

#include "quantum_gates/BaseGate.h"

class CircuitScence : public QGraphicsScene
{
  Q_OBJECT
public:
  explicit CircuitScence(QWidget *parent = nullptr);
  virtual ~CircuitScence();

signals:

private:
  QuantumGate *m_gate;
};

#endif // CIRCUITASSEMBLEWIDGET_H
