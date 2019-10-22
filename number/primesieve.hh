
#pragma once

namespace celp {

    template <typename _Tx>
    class psieve
    {

    public:
        psieve(_Tx size = 0);
        ~psieve();

    public:
        void resize(_Tx size);
        const bool* run();

    public:
        const bool operator[](_Tx index);

    public:
        const bool isValid() const;
        const bool* sieve() const;
        const _Tx size() const;
    
    private:
        bool m_IsValid;
        bool* m_Sieve;
        _Tx m_Size;

    };

}

#ifndef _CELP_NUMBER_PSIEVE_CC
#define _CELP_NUMBER_PSIEVE_CC

    #include <algorithm>

    template <typename _Tx>
    celp::psieve<_Tx>::psieve(_Tx size /* = 0 */)
        : m_Sieve(new bool[size])
        , m_IsValid(size == 0)
        , m_Size(size)
    {
        run();
    }

    template <typename _Tx>
    celp::psieve<_Tx>::~psieve()
    {
        delete[] m_Sieve;
    }

    template <typename _Tx>
    void celp::psieve<_Tx>::resize(_Tx size)
    {
        m_IsValid = false;
        delete[] m_Sieve;
        m_Sieve = new bool[size];
        m_Size = size;
    }

    template<typename _Tx>
    const bool* celp::psieve<_Tx>::run()
    {
        if (m_Size >= 1) m_Sieve[0] = false;
        if (m_Size >= 2) m_Sieve[1] = false;
        if (m_Size >= 3) {
            std::fill(m_Sieve + 2, m_Sieve + m_Size, true);
            for (_Tx i = 2; i < m_Size; ++i) {
                if (m_Sieve[i]) {
                    for (_Tx j = i * 2; j < m_Size; j *= 2) {
                        m_Sieve[j] = false;
                    }
                }
            }
        }
        m_IsValid = true;
        return m_Sieve;
    }

    template <typename _Tx>
    const bool celp::psieve<_Tx>::operator[](_Tx index)
    {
        return m_Sieve[index];
    }

    template <typename _Tx>
    const bool celp::psieve<_Tx>::isValid() const
    {
        return m_IsValid;
    }

    template <typename _Tx>
    const bool* celp::psieve<_Tx>::sieve() const
    {
        return m_Sieve;
    }

    template <typename _Tx>
    const _Tx celp::psieve<_Tx>::size() const
    {
        return m_Size;
    }

#endif // _CELP_NUMBER_PSIEVE_CC
