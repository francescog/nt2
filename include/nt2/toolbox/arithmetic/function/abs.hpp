/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_ABS_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_ABS_HPP_INCLUDED
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/arithmetic/include.hpp>

namespace nt2
{
  namespace functors
  {	       
    struct abs_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION( functors::abs_, abs, 1)
}
 
#include <nt2/toolbox/arithmetic/function/scalar/abs.hpp>
#include NT2_ARITHMETIC_INCLUDE(abs.hpp) 

#endif

// /////////////////////////////////////////////////////////////////////////////
// End of abs.hpp
// /////////////////////////////////////////////////////////////////////////////