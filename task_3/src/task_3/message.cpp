//
// Created by shumoff on 10.02.2020.
//
#include <ostream>
#include <iostream>
#include <sstream>

template <class ... Args>
int validate(std::ostream & stream, const char * string, Args const & ... args) {
    int str_args_amount = 0;
    const char *string_copy = string;
    while (*string_copy) {
        if (*string_copy++ == '%')
            ++str_args_amount;
    }

    if (str_args_amount != sizeof...(args))
        return 1;

    return 0;
}


template <class firstArg, class ... Args>
int message(std::ostream & stream, const char * string, firstArg const & first_arg, Args const & ... args) {
    if (validate(stream, string, first_arg, args...))
        return 1;

    while (*string != '%')
        stream << *string++;
    ++string;
    stream << first_arg;
    if constexpr (sizeof...(args) > 0)
        message(stream, string, args...);

    else {
        while (*string)
            stream << *string++;
    }
    return 0;
}

void test() {
    std::stringstream stream;
    message(std::cout, "bac % + % = % bac", 'a', 2, 3.0);

}
