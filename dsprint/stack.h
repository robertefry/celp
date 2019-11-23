
#pragma once

#include <stack>
#include <ostream>

template <typename T>
std::ostream& operator<<( std::ostream& stream, std::stack<T> stack ) {
    if ( stack.empty() ) return "[]";
    stream << '[' << stack.top();
    stack.pop();
    while ( !stack.empty() ) {
        stream << ',' << stack.top();
        stack.pop();
    }
    return stream << ']';
}
