
#pragma once

#include <string>

namespace celp {

    template <typename _Itr>
    std::string toString(const _Itr& first, const _Itr& last);

}

#ifndef _CELP_STRING_CC
#define _CELP_STRING_CC

    #include <sstream>

    template <typename _Itr>
    std::string celp::toString(const _Itr& first, const _Itr& last)
    {
        std::stringstream ss;
        ss << '[' << *first;
        for (_Itr itr = first + 1; itr != last; ++itr) {
            ss << ',' << *itr;
        }
        ss << ']';
        return ss.str();
    }

#endif // _CELP_STRING_CC
