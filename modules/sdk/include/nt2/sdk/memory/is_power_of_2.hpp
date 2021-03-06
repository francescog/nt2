/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_MEMORY_IS_POWER_OF_2_HPP_INCLUDED
#define NT2_SDK_MEMORY_IS_POWER_OF_2_HPP_INCLUDED

#include <nt2/sdk/meta/mpl.hpp>
#include <nt2/sdk/functor/functor.hpp>
#include <nt2/sdk/memory/meta/is_power_of_2.hpp>
#include <nt2/sdk/functor/preprocessor/function.hpp>

////////////////////////////////////////////////////////////////////////////////
// Check if a value is a power of 2
////////////////////////////////////////////////////////////////////////////////
namespace nt2
{
  namespace tag { struct is_power_of_2_ {}; }
  namespace memory
  {
    NT2_FUNCTION_IMPLEMENTATION(tag::is_power_of_2_, is_power_of_2, 1);
  }
}

#include <nt2/sdk/memory/details/is_power_of_2.hpp>

#endif
