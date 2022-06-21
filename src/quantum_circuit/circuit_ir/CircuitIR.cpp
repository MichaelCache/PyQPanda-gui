#include <assert.h>
#include "CircuitIR.h"

CircuitIR::CircuitIR(const std::string &name, uint64_t span_col)
    : m_name(name), m_span(0, span_col - 1)
{
}

std::shared_ptr<CircuitIR> CircuitIR::insert(std::shared_ptr<CircuitIR> other, row_t row, col_t col)
{
    auto span = other->span();
    row_t span_offset = span.m_upper - span.m_lower + 1;
    auto dest_span = other->span();
    dest_span.m_lower += span_offset;
    dest_span.m_upper += span_offset;
    if (m_child.count(col))
    {
        for (auto c : m_child.at(col))
        {
            if (c->span().overlap(dest_span))
            {
                return nullptr;
            }
        }
        other->moveTo(row);
        m_child.at(col).insert(other);
        return other;
    }
    else
    {
        m_child[col].insert(other);
        return other;
    }
}

void CircuitIR::setSpan(uint64_t lower, uint64_t upper)
{
    assert(lower <= upper);
    m_span.m_lower = lower;
    m_span.m_upper = upper;
}

void CircuitIR::moveTo(row_t dest_row)
{

    m_span.m_lower = dest_row;
    m_span.m_upper = m_span.m_lower + m_span.m_span - 1;
}

const Span &CircuitIR::span() const
{
    return m_span;
}

void CircuitIR::deleteGate(std::shared_ptr<CircuitIR> gate)
{
    for (auto i : m_child)
    {
        if (i.second.count(gate))
        {
            i.second.erase(gate);
        }
    }
}