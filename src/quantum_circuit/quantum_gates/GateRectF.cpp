#include "GateRectF.h"

namespace
{
    const qreal GATE_WIDTH = 30;
    const qreal GATE_HEIGHT = GATE_WIDTH;
}

GateRectF::GateRectF(qreal x, qreal y) : QRectF(x, y, GATE_WIDTH, GATE_HEIGHT),
                                         QColor(Qt::blue)
{
}

GateRectF::GateRectF(const QRectF &rect) : QRectF(rect),
                                           QColor(Qt::blue)
{
}
GateRectF::GateRectF(const GateRectF &rect) : QRectF(rect.x(), rect.y(), rect.width(), rect.height()),
                                              QColor(rect.toRgb())
{
}

GateRectF::~GateRectF() {}