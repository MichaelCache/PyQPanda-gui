#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QWidget>

#include "quantum_gates/BaseGate.h"
#include "quantum_gates/GateFactory.h"
#include "frame_line/FrameLine.h"

class GateFactory;

class CircuitScene : public QGraphicsScene
{
  Q_OBJECT
public:
  explicit CircuitScene(QWidget *parent = nullptr);
  virtual ~CircuitScene();

signals:
protected:

private:
  GateFactory *m_gate_factory;
  FrameLine *m_frame_line;
};

