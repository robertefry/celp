
#pragma once

#include <set>

namespace celp {

    template <typename _Tx>
    class prime
    {
    public:
        static bool isPrime(const _Tx& num);
        static bool isKnown(const _Tx& num);
        static std::set<_Tx> known();
    private:
        static std::set<_Tx> m_KnownPrimes;
    };

}

#ifndef _CELP_NUMBER_PRIME_CC
#define _CELP_NUMBER_PRIME_CC

    #include <algorithm>
    #include <cmath>

    template <typename _Tx>
    std::set<_Tx> celp::prime<_Tx>::m_KnownPrimes { 2 };

    template <typename _Tx>
    bool celp::prime<_Tx>::isPrime(const _Tx& num)
    {
        if (num < 0) return isPrime(-num);
        if (num == 0 || num == 1) return false;
        if (num != 2 && num % 2 == 0) return false;
        if (isKnown(num)) return true;
        for (_Tx i = 3; i <= sqrt(num); i += 2) {
            if (isPrime(i) && num % i == 0) return false;
        }
        m_KnownPrimes.insert(num);
        return true;
    }

    template <typename _Tx>
    bool celp::prime<_Tx>::isKnown(const _Tx& num)
    {
        auto found = std::find(m_KnownPrimes.begin(), m_KnownPrimes.end(), num);
        return found != m_KnownPrimes.end();
    }

    template <typename _Tx>
    std::set<_Tx> celp::prime<_Tx>::known()
    {
        return m_KnownPrimes;
    }

#endif // _CELP_NUMBER_PRIME_CC
