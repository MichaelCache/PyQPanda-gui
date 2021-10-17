#include "CircuitScence.h"

CircuitScence::CircuitScence(QWidget *parent)
    : QGraphicsScene(parent)
{
    m_gate = new BaseGate(this);

    addItem(m_gate);
}

CircuitScence::~CircuitScence() {}