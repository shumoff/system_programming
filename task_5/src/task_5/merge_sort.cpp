//
// Created by shumoff on 15.02.2020.
//
#include <iostream>

template<typename T>
void merge_sort(T first, T last) {
    int size = last - first;
    if (size == 0 || size == 1) return;

    T center = first + (size / 2);

    merge_sort(first, center);
    merge_sort(center, last);

    T n_1 = first;
    T n_2 = center;

    auto list = new typename std::iterator_traits<T>::value_type[size];

    size = 0;
    while(n_1 != center || n_2 != last)
        if(n_1 == center)
            while(n_2 != last) {
                list[size++] = *n_2++;
            }
        else if(n_2 == last)
            while(n_1 != center) {
                list[size++] = *n_1++;
            }
        else if(*n_1 < *n_2) {
            list[size++] = *n_1++;
        }
        else {
            list[size++] = *n_2++;
        }

    size = 0;
    while(first != last) {
        *first++ = list[size++];
    }
    delete[] list;
}
