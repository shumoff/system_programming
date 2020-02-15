//
// Created by shumoff on 15.02.2020.
//

#ifndef TASK_5_OSTREAM_ITERATOR_H
#define TASK_5_OSTREAM_ITERATOR_H

#include <ostream>

template<class T>
struct OstreamIterator {
public:
    OstreamIterator(std::ostream& stream, const char* delimiter, int N):
    stream_(&stream), delimiter_(delimiter), N_(N) {
        n_ = 1;
    }

    OstreamIterator& operator=(T sym) {
        if (n_ == N_) {
            n_ = 1;
            *stream_ << sym << delimiter_;
        }
        else
            ++n_;
        return *this;
    }

    ~OstreamIterator() = default;

private:
    std::ostream* stream_;
    const char* delimiter_;
    int n_;
    int N_;
};

#endif //TASK_5_OSTREAM_ITERATOR_H
