// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

typedef char qi __attribute__ ((mode(QI)));
typedef short hi __attribute__ ((mode(HI)));
typedef int si __attribute__ ((mode(SI)));
typedef long long di __attribute__ ((mode(DI)));

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
typedef sf v4sf __attribute__ ((vector_size (16)));
typedef df v2df __attribute__ ((vector_size (16)));

typedef qi v32qi __attribute__ ((vector_size (32)));
typedef hi v16hi __attribute__ ((vector_size (32)));
typedef si v8si __attribute__ ((vector_size (32)));
typedef di v4di __attribute__ ((vector_size (32)));
typedef sf v8sf __attribute__ ((vector_size (32)));
typedef df v4df __attribute__ ((vector_size (32)));

typedef qi v64qi __attribute__ ((vector_size (64)));
typedef hi v32hi __attribute__ ((vector_size (64)));
typedef si v16si __attribute__ ((vector_size (64)));
typedef di v8di __attribute__ ((vector_size (64)));
typedef sf v16sf __attribute__ ((vector_size (64)));
typedef df v8df __attribute__ ((vector_size (64)));

typedef qi __gcc_qi;
typedef hi __gcc_hi;
typedef si __gcc_si;
typedef di __gcc_di;
typedef sf __gcc_sf; 
typedef df __gcc_df;
typedef v8qi __gcc_v8qi;
typedef v4hi __gcc_v4hi;
typedef v2si __gcc_v2si;
typedef v1di __gcc_v1di;
typedef v2sf __gcc_v2sf;
typedef v16qi __gcc_v16qi;
typedef v8hi __gcc_v8hi;
typedef v4si __gcc_v4si;
typedef v2di __gcc_v2di;
typedef v4sf __gcc_v4sf;
typedef v2df __gcc_v2df;
typedef v32qi __gcc_v32qi;
typedef v16hi __gcc_v16hi;
typedef v8si __gcc_v8si;
typedef v4di __gcc_v4di;
typedef v8sf __gcc_v8sf;
typedef v4df __gcc_v4df;
typedef v64qi __gcc_v64qi;
typedef v32hi __gcc_v32hi;
typedef v16si __gcc_v16si;
typedef v8di __gcc_v8di;
typedef v16sf __gcc_v16sf;
typedef v8df __gcc_v8df;

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
