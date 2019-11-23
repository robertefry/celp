
#pragma once

#include <set>

namespace celp {

    template <typename _Tx>
    class primesearch
    {
    public:
        bool isPrime(const _Tx& num);
        bool isKnownPrime(const _Tx& num);
        const std::set<_Tx> getKnownPrimes() const;
    private:
        std::set<_Tx> m_KnownPrimes { 2 };
    };

    template <typename _Tx>
    static bool isPrime(const _Tx& num);

}

#include <algorithm>
#include <cmath>

template <typename _Tx>
static bool celp::isPrime(const _Tx& num)
{
    primesearch<_Tx> search;
    return search.isPrime(num);
}

template <typename _Tx>
bool celp::primesearch<_Tx>::isPrime(const _Tx& num)
{
    if (num < 0) return isPrime(-num);
    if (num == 0 || num == 1) return false;
    if (num != 2 && num % 2 == 0) return false;
    if (isKnownPrime(num)) return true;
    for (_Tx i = 3; i <= sqrt(num); i += 2) {
        if (isPrime(i) && num % i == 0) return false;
    }
    m_KnownPrimes.insert(num);
    return true;
}

template <typename _Tx>
bool celp::primesearch<_Tx>::isKnownPrime(const _Tx& num)
{
    auto found = std::find(m_KnownPrimes.begin(), m_KnownPrimes.end(), num);
    return found != m_KnownPrimes.end();
}

template <typename _Tx>
const std::set<_Tx> celp::primesearch<_Tx>::getKnownPrimes() const
{
    return m_KnownPrimes;
}
