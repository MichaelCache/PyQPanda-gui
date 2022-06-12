#pragma once

#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QString>

#include "../quantum_gates/GateRectF.h"
#include "../quantum_gates/BaseGate.h"

class CircuitLine : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit CircuitLine(const QString &label, const QPointF &pos, QObject *parent = nullptr);
    virtual ~CircuitLine();

    void showValidPos(const QRectF& rect);
    void hideValidPos();

signals:
    void isInValidPos(bool, QPointF scene_pos);

public slots:
    
    
    void checkValidPos(QRectF scene_rect, BaseGate *);
    void occupyPos(bool);

private:
    QGraphicsTextItem *m_line_label;
    QGraphicsLineItem *m_frame_line;
    QGraphicsRectItem *m_virtual_gate;
    double m_step{30};
    QPointF m_valid_pos{m_step, 0};
};
