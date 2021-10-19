#ifndef CIRCUITASSEMBLEWIDGET_H
#define CIRCUITASSEMBLEWIDGET_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QWidget>

#include "quantum_gates/BaseGate.h"
#include "gate_factory/BaseFactory.h"

class CircuitScence : public QGraphicsScene
{
  Q_OBJECT
public:
  explicit CircuitScence(QWidget *parent = nullptr);
  virtual ~CircuitScence();

signals:

private:
  BaseGate *m_gate;
  // QList < BaseFa
};

#endif // CIRCUITASSEMBLEWIDGET_H
