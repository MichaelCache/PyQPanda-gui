#pragma once

#include <cstdint>
class Span
{

public:
    Span(uint64_t lower, uint64_t upper);
    ~Span() = default;
    
    bool overlap(const Span& other);

// private:
    uint64_t m_lower;
    uint64_t m_upper;
};
