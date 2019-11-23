
#pragma once

#include <map>
#include <ostream>

template <typename S, typename T>
std::ostream& operator<<( std::ostream& stream, const std::pair<S,T>& pair ) {
    return stream << pair.first << ':' << pair.second;
}

template <typename S, typename T>
std::ostream& operator<<( std::ostream& stream, const std::map<S,T>& map ) {
    stream << '[';
    std::size_t count = 0;
    for ( const std::pair<S,T>& pair : map ) {
        stream << pair;
        if ( count++ < map.size() ) stream << ',';
    }
    return stream << ']';
}
