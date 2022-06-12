#pragma once

#include "Span.h"
#include <unordered_map>
#include <memory>

class CircuitIR
{
public:
    using col_t = uint64_t;
    CircuitIR(const std::string &name, uint64_t lower, uint64_t upper);
    ~CircuitIR() = default;
    std::shared_ptr<CircuitIR> insert(col_t col, std::shared_ptr<CircuitIR> other);
    void setSpan(uint64_t lower, uint64_t upper);

private:
    std::string m_name;
    std::vector<double> m_args;
    std::vector<uint64_t> m_controls;

    Span m_span;
    std::unordered_map<col_t, std::vector<std::shared_ptr<CircuitIR>>> m_child;
};
