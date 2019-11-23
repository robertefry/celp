
#pragma once

#include <cstddef>

namespace celp {

    class primesieve
    {

    public:

        primesieve(std::size_t size = 0);
        ~primesieve();

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

#include <algorithm>

celp::primesieve::primesieve(std::size_t size /* = 0 */)
    : m_Sieve(new bool[size])
    , m_IsValid(size == 0)
    , m_Size(size)
{
    run();
}

celp::primesieve::~primesieve()
{
    delete[] m_Sieve;
}

void celp::primesieve::resize(std::size_t size)
{
    m_IsValid = false;
    delete[] m_Sieve;
    m_Sieve = new bool[size];
    m_Size = size;
}

const bool* celp::primesieve::run()
{
    if (isValid()) return;
    if (m_Size >= 1) m_Sieve[0] = false;
    if (m_Size >= 2) m_Sieve[1] = false;
    if (m_Size >= 3) {
        std::fill(m_Sieve + 2, m_Sieve + m_Size, true);
        for (std::size_t i = 2; i < m_Size; ++i) {
            if (m_Sieve[i]) {
                for (std::size_t j = i * 2; j < m_Size; j += i) {
                    m_Sieve[j] = false;
                }
            }
        }
    }
    m_IsValid = true;
    return m_Sieve;
}

const bool celp::primesieve::isValid() const
{
    return m_IsValid;
}

const bool* celp::primesieve::sieve() const
{
    return m_Sieve;
}

const std::size_t celp::primesieve::size() const
{
    return m_Size;
}

const bool celp::primesieve::operator[](std::size_t index)
{
    return m_Sieve[index];
}
