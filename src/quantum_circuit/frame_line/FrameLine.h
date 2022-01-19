#pragma once

#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QString>

#include "../quantum_gates/GateRectF.h"
// #include 

class FrameLine : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit FrameLine(const QString &label, const QPointF& pos, QObject *parent = nullptr);
    virtual ~FrameLine();

private:
    QGraphicsTextItem* m_line_label;
    QGraphicsLineItem* m_frame_line;
    GateRectF m_virtual_gate;
};
