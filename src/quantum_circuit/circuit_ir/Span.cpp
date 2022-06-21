#include "Span.h"
#include <assert.h>

Span::Span(uint64_t lower, uint64_t upper)
{
    assert(lower <= upper);
    m_lower = lower;
    m_upper = upper;
    m_span = m_upper - m_lower + 1;
}

bool Span::overlap(const Span &other) const
{
    // not overlap is easy to check
    if (other.m_upper < this->m_lower || other.m_lower > this->m_upper)
    {
        return false;
    }
    else
    {
        return true;
    }
}
