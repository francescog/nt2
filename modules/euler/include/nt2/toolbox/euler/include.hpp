//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EULER_INCLUDE_HPP_INCLUDED
#define NT2_TOOLBOX_EULER_INCLUDE_HPP_INCLUDED
#include <nt2/sdk/simd/preprocessor/include.hpp>

#define NT2_EULER_BASE() nt2/toolbox/euler/function/scalar/
#define NT2_EULER_RELATIVE() nt2/toolbox/euler/function/

#define NT2_EULER_INCLUDE(F) NT2_SIMD_RELATIVE_INCLUDE(NT2_EULER_RELATIVE, F)

#endif
