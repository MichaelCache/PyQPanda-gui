#include "CircuitScence.h"

CircuitScence::CircuitScence(QWidget *parent)
    : QGraphicsScene(parent)
{
    // m_gate = new BaseGate(this);
    m_gate_factory = new GateFactory("H", this);
    addItem(m_gate_factory);
}

CircuitScence::~CircuitScence() {}