/**
 * @file    utils.h
 * @ingroup base
 * @brief   Shared utility macros and functions.
 *
 * Copyright (c) 2013-2021 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#pragma once

#include <cstddef>

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
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

// A macro for snprintf support in Visual Studio
#if _MSC_VER
#define snprintf _snprintf
#endif

