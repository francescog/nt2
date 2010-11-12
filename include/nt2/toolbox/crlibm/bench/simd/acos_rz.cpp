//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/crlibm/include/acos_rz.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/simd/native.hpp>
#include <cmath>

typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
typedef nt2::simd::native<float,ext_t> vfloat;
typedef nt2::simd::native<double,ext_t> vdouble;
typedef nt2::simd::native<int32_t,ext_t> vint32_t;

//////////////////////////////////////////////////////////////////////////////
// Simd Runtime benchmark for functor<acos_rz_> from crlibm
//////////////////////////////////////////////////////////////////////////////
using nt2::crlibm::acos_rz_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, V1 , V2)

NT2_TIMING(nt2::crlibm::acos_rz_,(RS(vfloat,-1.0f,1.0f)))
NT2_TIMING(nt2::crlibm::acos_rz_,(RS(vdouble,-1.0,1.0)))
NT2_TIMING(nt2::crlibm::acos_rz_,(RS(vint32_t,-1.0,1.0)))

#undef RS