#include "CircuitIR.h"

CircuitIR::CircuitIR(const std::string &name, uint64_t lower, uint64_t upper)
    : m_name(name), m_span(lower, upper)
{
}

std::shared_ptr<CircuitIR> CircuitIR::insert(col_t col, std::shared_ptr<CircuitIR> other)
{
    auto col_gates = m_child[col];
    for (auto &gate : col_gates)
    {
        if (other->m_span.overlap(gate->m_span))
        {
            return nullptr;
        }
    }
    m_child[col].push_back(other);
    return other;
}