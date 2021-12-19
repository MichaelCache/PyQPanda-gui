#include "GateFont.h"

GateFont::GateFont() : QFont(), QColor(Qt::white)
{
    setBold(true);
    setPixelSize(20);
    setFamily("Consolas");
}

GateFont::~GateFont()
{
}