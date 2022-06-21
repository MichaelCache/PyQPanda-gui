#pragma once

#include "Span.h"
#include <unordered_map>
#include <memory>
#include <vector>
#include <set>

class CircuitIR
{
public:
    using col_t = uint64_t;
    using row_t = uint64_t;
    CircuitIR(const std::string &name, uint64_t span_col);
    ~CircuitIR() = default;
    std::shared_ptr<CircuitIR> insert(std::shared_ptr<CircuitIR> other, row_t row, col_t col);
    void setSpan(uint64_t lower, uint64_t upper);
    void moveTo(row_t dest_row);
    const Span &span() const;
    
    void deleteGate(std::shared_ptr<CircuitIR>);
private:
    std::string m_name;
    std::vector<double> m_args;
    std::vector<uint64_t> m_controls;

    Span m_span;
    // std::set<std::shared_ptr<CircuitIR>> m_child;
    std::unordered_map<col_t, std::set<std::shared_ptr<CircuitIR>>> m_child;
};
