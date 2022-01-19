#include "GateFont.h"

GateFont::GateFont(int font_size, const QColor &color)
    : QFont("Consolas", font_size, QFont::Normal),
      QColor(color)
{
}

GateFont::~GateFont()
{
}