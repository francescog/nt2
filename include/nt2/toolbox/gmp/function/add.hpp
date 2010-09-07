/******************************************************************************
 *        Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand      
 *        Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI           
 *                                                                             
 *          Distributed under the Boost Software License, Version 1.0.         
 *                 See accompanying file LICENSE.txt or copy at                
 *                     http://www.boost.org/LICENSE_1_0.txt                    
 *****************************************************************************/
#ifndef NT2_TOOLBOX_GMP_FUNCTION_ADD_HPP_INCLUDED
#define NT2_TOOLBOX_GMP_FUNCTION_ADD_HPP_INCLUDED
#include <nt2/include/simd.hpp>,
#include <nt2/include/functor.hpp>
#include <nt2/core/numeric/preprocessor/include.hpp>

namespace nt2 { namespace functors
  {	       
    struct add_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(gmp::add_, add, 2)
}
 
#include <nt2/core/numeric/function/details/scalar/add.hpp>
// Uncomment the following line if you implement a proper simd version
//#include NT2_INCLUDE_FROM(NT2_GMP_BASE,add.hpp) 

 
#endif
