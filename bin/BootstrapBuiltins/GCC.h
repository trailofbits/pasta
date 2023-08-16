// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// typedef void v;
// typedef char c;
// typedef short s;
// typedef int i;
// typedef __fp16 h;
// typedef _Float16 x;
// typedef __bf16 y;
// typedef float f;
// typedef double d;

typedef unsigned char qi __attribute__ ((mode(QI)));
typedef signed char uqi __attribute__ ((mode(QI)));
typedef short hi __attribute__ ((mode(HI)));
typedef unsigned short uhi __attribute__ ((mode(HI)));
typedef int si __attribute__ ((mode(SI)));
typedef unsigned usi __attribute__ ((mode(SI)));
typedef long long di __attribute__ ((mode(DI)));
typedef unsigned long long udi __attribute__ ((mode(DI)));

typedef int int32_t;
typedef unsigned uint32_t;

typedef long long int64_t;
typedef unsigned long long uint64_t;

typedef _Float16 hf __attribute__ ((mode(HF)));
typedef float sf __attribute__ ((mode(SF)));
typedef double df __attribute__ ((mode(DF)));

typedef qi v8qi __attribute__ ((vector_size (8)));
typedef hi v4hi __attribute__ ((vector_size (8)));
typedef si v2si __attribute__ ((vector_size (8)));
typedef di v1di __attribute__ ((vector_size (8)));
typedef sf v2sf __attribute__ ((vector_size (8)));

typedef qi v16qi __attribute__ ((vector_size (16)));
typedef hi v8hi __attribute__ ((vector_size (16)));
typedef si v4si __attribute__ ((vector_size (16)));
typedef di v2di __attribute__ ((vector_size (16)));
typedef hf v8hf __attribute__ ((vector_size (16)));
typedef sf v4sf __attribute__ ((vector_size (16)));
typedef df v2df __attribute__ ((vector_size (16)));

typedef qi v32qi __attribute__ ((vector_size (32)));
typedef hi v16hi __attribute__ ((vector_size (32)));
typedef si v8si __attribute__ ((vector_size (32)));
typedef di v4di __attribute__ ((vector_size (32)));
typedef hf v16hf __attribute__ ((vector_size (32)));
typedef sf v8sf __attribute__ ((vector_size (32)));
typedef df v4df __attribute__ ((vector_size (32)));

typedef qi v64qi __attribute__ ((vector_size (64)));
typedef uqi v64uqi __attribute__ ((vector_size (64)));
typedef hi v32hi __attribute__ ((vector_size (64)));
typedef uhi v32uhi __attribute__ ((vector_size (64)));
typedef si v16si __attribute__ ((vector_size (64)));
typedef usi v16usi __attribute__ ((vector_size (64)));
typedef di v8di __attribute__ ((vector_size (64)));
typedef udi v8udi __attribute__ ((vector_size (64)));
typedef hf v32hf __attribute__ ((vector_size (64)));
typedef sf v16sf __attribute__ ((vector_size (64)));
typedef df v8df __attribute__ ((vector_size (64)));

typedef si v256si __attribute__ ((vector_size (1024)));

#if defined(__LP64__)
// LP64 machine (sizeof(long) == 8), macOS or Linux
typedef unsigned long size_t;
typedef long intptr_t;
typedef unsigned long uintptr_t;

#elif defined(_WIN64)
// 64-bit Windows
typedef unsigned long long size_t;
typedef long long intptr_t;
typedef unsigned long long uintptr_t;

#else
// 32 bit
typedef unsigned long size_t;
typedef long intptr_t;
typedef unsigned long uintptr_t;
#endif

// Compatibility with xmmintrin.h
#define __m128i v4si
#define __m256i v8si
#define __m128d v2df
#define __m256d v4df
#define __v4si v4si
#define __v4sf v4sf

#define __m128 v4sf
#define __m256 v8sf
#define  __m128_u v4sf
#define __m64 uint64_t
#define __int32 int
#define __int64 long long

// Compatibility with microsoft stuff.
#define VOID void

// Compatibility with CBMC types.
#define __gcc_qi qi
#define __gcc_hi hi
#define __gcc_si si
#define __gcc_di di
#define __gcc_sf sf
#define __gcc_df df
#define __gcc_v8qi v8qi
#define __gcc_v4hi v4hi
#define __gcc_v2si v2si
#define __gcc_v1di v1di
#define __gcc_v2sf v2sf
#define __gcc_v16qi v16qi
#define __gcc_v8hi v8hi
#define __gcc_v4si v4si
#define __gcc_v2di v2di
#define __gcc_v4sf v4sf
#define __gcc_v2df v2df
#define __gcc_v32qi v32qi
#define __gcc_v16hi v16hi
#define __gcc_v8si v8si
#define __gcc_v4di v4di
#define __gcc_v8sf v8sf
#define __gcc_v4df v4df
#define __gcc_v64qi v64qi
#define __gcc_v32hi v32hi
#define __gcc_v16si v16si
#define __gcc_v8di v8di
#define __gcc_v16sf v16sf
#define __gcc_v8df v8df
#define __gcc_v8hf v8hf
#define __gcc_v16hf v16hf
#define __gcc_v32hf v32hf
#define __gcc_v256si v256si
#define __gcc_v16usi v16usi
#define __gcc_v32uhi v32uhi
#define __gcc_v64uqi v64uqi
#define __gcc_v8udi v8udi

typedef const float * pcfloat;
typedef const double * pcdouble;
typedef const v2df * pcv2df;
typedef const v2di * pcv2di;
typedef const long long * pcint64;
typedef const char * pcchar;
typedef const v4df * pcv4df;
typedef const v4di * pcv4di;
typedef v4di * pv4di;
typedef const v4sf * pcv4sf;
typedef const int * pcint;
typedef char * pchar;
typedef double * pdouble;
typedef float * pfloat;
typedef const v4si * pcv4si;
typedef v4si * pv4si;
typedef v2di * pv2di;
typedef const v8sf * pcv8sf;
typedef const v8si * pcv8si;
typedef v8si * pv8si;
typedef v2df * pv2df;
typedef v4df * pv4df;
typedef v4sf * pv4sf;
typedef v8sf * pv8sf;

#define __CPROVER_Float128 __float128
#define dfloat32_type_node __float32
#define dfloat64_type_node __float64
#define dfloat128_type_node __float128

#define ptest ...

// bootstrap.py will use this file with an `-include`, so that another file
// with lots of builtin declarations ends up here.
