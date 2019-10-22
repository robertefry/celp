
#pragma once

#include <cstddef>

namespace celp {

    class psieve
    {

    public:

        psieve(std::size_t size = 0);
        ~psieve();

        void resize(std::size_t size);
        const bool* run();

        const bool isValid() const;
        const bool* sieve() const;
        const std::size_t size() const;

        const bool operator[](std::size_t index);
    
    private:

        bool m_IsValid;
        bool* m_Sieve;
        std::size_t m_Size;

    };

}

#ifndef _CELP_NUMBER_PSIEVE_CC
#define _CELP_NUMBER_PSIEVE_CC

    #include <algorithm>

    celp::psieve::psieve(std::size_t size /* = 0 */)
        : m_Sieve(new bool[size])
        , m_IsValid(size == 0)
        , m_Size(size)
    {
        run();
    }

    celp::psieve::~psieve()
    {
        delete[] m_Sieve;
    }

    void celp::psieve::resize(std::size_t size)
    {
        m_IsValid = false;
        delete[] m_Sieve;
        m_Sieve = new bool[size];
        m_Size = size;
    }

    const bool* celp::psieve::run()
    {
        if (m_Size >= 1) m_Sieve[0] = false;
        if (m_Size >= 2) m_Sieve[1] = false;
        if (m_Size >= 3) {
            std::fill(m_Sieve + 2, m_Sieve + m_Size, true);
            for (std::size_t i = 2; i < m_Size; ++i) {
                if (m_Sieve[i]) {
                    for (std::size_t j = i * 2; j < m_Size; j *= 2) {
                        m_Sieve[j] = false;
                    }
                }
            }
        }
        m_IsValid = true;
        return m_Sieve;
    }

    const bool celp::psieve::isValid() const
    {
        return m_IsValid;
    }

    const bool* celp::psieve::sieve() const
    {
        return m_Sieve;
    }

    const std::size_t celp::psieve::size() const
    {
        return m_Size;
    }

    const bool celp::psieve::operator[](std::size_t index)
    {
        return m_Sieve[index];
    }

#endif // _CELP_NUMBER_PSIEVE_CC
