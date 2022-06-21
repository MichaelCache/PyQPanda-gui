#pragma once

#include <QGraphicsItemGroup>
#include <QVector>
#include <QSet>

#include "circuit_line/CircuitLine.h"
#include "quantum_gates/BaseGate.h"
#include "circuit_ir/CircuitIR.h"

class Circuit : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Circuit(const QPointF &pos, QGraphicsItem *parent = nullptr);
    virtual ~Circuit() = default;
    virtual QRectF boundingRect() const override;

    void pushCircLine(uint64_t row_num);
    void popCircLine();

    void tryAddGate(BaseGate *);

private slots:
    void addGate(BaseGate *, uint64_t, uint64_t);
    void deleteGate(BaseGate *);
    void showValidGatePosBox(BaseGate *);
    void hideValidGatePosBox();
    void checkValidPos(BaseGate *);

private:
    void connectGate(BaseGate *);

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    // virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    // virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    // virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    QSet<BaseGate *> m_gates;
    QVector<CircuitLine *> m_circ_lines;
    const double m_circline_interval{40};
    const uint64_t m_init_lines{3};
    CircuitIR m_circ;
    int m_nearest_line_idx;
};
