/**
 * @file    util.h
 * @ingroup base
 * @brief   Shared utility macros and functions.
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef SRC_BASE_UTILS_H_
#define SRC_BASE_UTILS_H_

#include <cstddef>

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

// A macro to enable the use of the nullptr keyword (NULL on older compiler)
#ifdef _MSC_VER
#if _MSC_VER < 1600
#define nullptr NULL
#endif
#else
#ifndef __GXX_EXPERIMENTAL_CXX0X__
#define nullptr NULL
#endif
#endif

#endif  // SRC_BASE_UTILS_H_
