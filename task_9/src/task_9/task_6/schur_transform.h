//
// Created by shumoff on 14.02.2020.
//

#ifndef TASK_6_SCHUR_TRANSFORM_H
#define TASK_6_SCHUR_TRANSFORM_H
#include "polynomial.h"


template<class T>
typename std::enable_if<std::is_arithmetic<T>::value, Polynomial<T>>::type
schur_transform(Polynomial<T> polynomial);

template<class T>
typename std::enable_if<!std::is_arithmetic<T>::value, Polynomial<T>>::type
schur_transform(Polynomial<T> polynomial);

#endif //TASK_6_SCHUR_TRANSFORM_H
