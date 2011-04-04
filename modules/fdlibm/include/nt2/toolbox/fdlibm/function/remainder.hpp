//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_FDLIBM_FUNCTION_REMAINDER_HPP_INCLUDED
#define NT2_TOOLBOX_FDLIBM_FUNCTION_REMAINDER_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/fdlibm/include.hpp>

namespace nt2 { namespace fdlibm { namespace tag
  {         
    struct remainder_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(fdlibm::tag::remainder_, remainder, 2)
  } }
 
#include <nt2/toolbox/fdlibm/function/scalar/remainder.hpp>
// #include NT2_FDLIBM_INCLUDE(remainder.hpp) 

 
#endif

// modified by jt the 29/12/2010