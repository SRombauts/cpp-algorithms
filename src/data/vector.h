/**
 * @file    vector.h
 * @ingroup data
 * @brief   Implementation of dynamic array (a "vector").
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef SRC_DATA_VECTOR_H_
#define SRC_DATA_VECTOR_H_

#include "base/utils.h"

/**
 * @brief Implementation of dynamic array (a "vector").
 */
class Vector {
 public:
    Vector();
    ~Vector();  // no need for virtual dtor

 private:
    const char* array_;

    DISALLOW_COPY_AND_ASSIGN(Vector);
};

#endif  // SRC_DATA_VECTOR_H_

