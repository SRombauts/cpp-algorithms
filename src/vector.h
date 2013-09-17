/**
 * @file    vector.h
 * @ingroup CppAlgorithms
 * @brief   Implementation of dynamic array (a "vector").
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "utils.h"


/**
 * @brief Implementation of dynamic array (a "vector").
 */
class Vector
{
public:
   Vector();
   ~Vector(); // no need for virtual dtor

private:
   const char* array_;

   DISALLOW_COPY_AND_ASSIGN(Vector);
};
