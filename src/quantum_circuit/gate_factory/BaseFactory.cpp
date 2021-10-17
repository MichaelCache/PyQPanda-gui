#include "BaseFactory.h"

BaseGateFactory::BaseGateFactory(QWidget *parent = nullptr) : m_parent(parent) {}

BaseGateFactory::~BaseGateFactory() {}

BaseGate *createGate(const QString &name)
{
    return new ()
}