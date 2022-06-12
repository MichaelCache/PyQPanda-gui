#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QWidget>
#include <QSet>
#include <QRectF>

#include "quantum_gates/BaseGate.h"
#include "circuit_line/CircuitLine.h"
#include "GateFactory.h"
#include "Circuit.h"

class GateFactory;

class CircuitScene : public QGraphicsScene
{
  Q_OBJECT
public:
  explicit CircuitScene(QObject *parent = nullptr);
  virtual ~CircuitScene();
  void addGate(BaseGate *);

  // to show mose coord
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

private slots:
  // void temporaryConnectDelete(BaseGate *);
  // void temporaryDisConnectDelete(BaseGate *);
  // void deleteItem(QGraphicsItem *);

private:
  GateFactory *m_gate_factory;
  Circuit *m_circ;
};
