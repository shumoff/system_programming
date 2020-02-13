//
// Created by shumoff on 10.02.2020.
//
#include <ostream>

template <class ... Types>
int validate(const char * string, Types const & ... args) {
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


template <class firstType, class ... Types>
int message(std::ostream & thread, const char * string, firstType const & first_arg, Types const & ... args) {
    if (validate(string, first_arg, args...))
        return 1;

    while (*string != '%')
        thread << *string++;
    ++string;
    thread << first_arg;
    if constexpr (sizeof...(args) > 0)
        message(thread, string, args...);
    else {
        while (*string)
            thread << *string++;
    }
    return 0;
}