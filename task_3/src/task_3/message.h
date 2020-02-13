//
// Created by shumoff on 10.02.2020.
//

#ifndef TASK_3_MESSAGE_H
#define TASK_3_MESSAGE_H
template <class firstArg, class ... Args>
int message(std::ostream & stream, const char * string, firstArg const & first_arg, Args const & ... args);

void test();

template <class ... Args>
int validate(std::ostream & stream, const char * string, Args const & ... args);
#endif //TASK_3_MESSAGE_H
