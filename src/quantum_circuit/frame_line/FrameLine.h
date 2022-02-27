#pragma once

#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QString>

#include "../quantum_gates/GateRectF.h"
#include "../quantum_gates/BaseGate.h"

class FrameLine : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit FrameLine(const QString &label, const QPointF &pos, QObject *parent = nullptr);
    virtual ~FrameLine();

signals:
    void isInValidPos(bool, QPointF scene_pos);

public slots:
    void showValidPos(QRectF rect);
    void hideValidPos();
    void checkValidPos(QRectF scene_rect, BaseGate *);
    void occupyPos(bool);

private:
    QGraphicsTextItem *m_line_label;
    QGraphicsLineItem *m_frame_line;
    QGraphicsRectItem *m_virtual_gate;
    double m_step{30};
    QPointF m_valid_pos{m_step, 0};
};
