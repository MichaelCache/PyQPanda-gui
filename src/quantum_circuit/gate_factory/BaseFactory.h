#include <QString>
#include <QWidget>

#include "../quantum_gates/BaseGate.h"

class BaseGateFactory
{
public:
    BaseGateFactory(QWidget *parent = nullptr);
    virtual ~BaseGateFactory();
    virtual BaseGate *createGate(const QString &name);

protected:
    QWidget *m_parent;
};