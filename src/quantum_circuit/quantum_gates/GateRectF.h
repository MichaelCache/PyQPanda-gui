#pragma once

#include <QRectF>
#include <QColor>

/**
 * @brief Gate rect with default background color blue 
 * default left top at (0,0) with 30*30 pix
 */
class GateRectF : public QRectF, public QColor
{
public:
    explicit GateRectF(qreal x =0, qreal y=0);
    explicit GateRectF(const QRectF& rect);
    explicit GateRectF(const GateRectF& rect);
    virtual ~GateRectF();
};