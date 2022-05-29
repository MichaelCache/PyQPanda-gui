#pragma once

#include <QGraphicsItemGroup>
#include <QVector>

#include "circuit_line/CircuitLine.h"
#include "quantum_gates/BaseGate.h"

class Circuit : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Circuit(const QPointF &pos, QObject *parent = nullptr);
    virtual ~Circuit() = default;
    virtual QRectF boundingRect() const override;

    void pushFrameLine();
    void popFrameLine();

    void addGate(BaseGate *);

private:
    void tryAddGate(BaseGate *);

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    // virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    // virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    // virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    QVector<BaseGate *> m_gates;
    QVector<CircuitLine *> m_circ_lines;
    const double m_circ_interval{40};
    const uint64_t m_init_lines{3};
};
