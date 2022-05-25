#pragma once

#include <QGraphicsItemGroup>
#include <QVector>

#include "circuit_line/CircuitLine.h"
#include "quantum_gates/BaseGate.h"

class Circuit : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit Circuit(const QPointF &pos, QObject *parent = nullptr);
    virtual ~Circuit() = default;

    void pushFrameLine();
    void popFrameLine();

private:
    QVector<BaseGate *> m_gates;
    QVector<FrameLine *> m_circ_lines;
    const double m_circ_interval{40};
    const uint64_t m_init_lines{3};
};
