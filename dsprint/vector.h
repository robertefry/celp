
#pragma once

#include <vector>
#include <ostream>

template <typename T>
std::ostream& operator<<( std::ostream& stream, const std::vector<T>& vec ) {
    if ( vec.size() == 0 ) return "[]";
    stream << '[' << vec[0];
    for ( std::size_t i = 1; i < vec.size(); ++i ) {
        stream << ',' << vec[i];
    }
    return stream << ']';
}
