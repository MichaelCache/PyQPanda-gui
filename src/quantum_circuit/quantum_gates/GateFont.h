#pragma once

#include <QFont>
#include <QColor>

/**
 * @brief Gate name font in will be drawed in GateRect
 * default is bold, consolas, white with pix 20
 */
class GateFont : public QFont, public QColor
{
public:
    explicit GateFont();
    virtual ~GateFont();
};