//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 core - value_at test"

//==============================================================================
// Test behavior of nt2::value_at with scalar in ref and cref scenarii
//==============================================================================
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/core/functions/value_at.hpp>

NT2_TEST_CASE ( value_at_const_scalar )
{
  using nt2::value_at;

  boost::array<int,4> p = {1,2,3,4};

  NT2_TEST_EQUAL( value_at(7,1)         ,    7 );
  NT2_TEST_EQUAL( value_at(7,p)         ,    7 );
  NT2_TEST_EQUAL( value_at(42,1,2)      ,   42 );
  NT2_TEST_EQUAL( value_at(101,1,2,3)   ,  101 );
  NT2_TEST_EQUAL( value_at(1337,1,2,3,4), 1337 );
}

NT2_TEST_CASE ( value_at_non_const_scalar )
{
  using nt2::value_at;

  float f;

  boost::array<int,4> p = {1,2,3,4};

  value_at(f,1) = 0.5f;
  NT2_TEST_EQUAL( f , 0.5f );

  value_at(f,p) = 2.f;
  NT2_TEST_EQUAL( f , 2.f );

  value_at(f,1,2) = 4.2f;
  NT2_TEST_EQUAL( f , 4.2f );

  value_at(f,1,2,3) = 1.01f;
  NT2_TEST_EQUAL( f , 1.01f );

  value_at(f,1,2,3,4) = 13.37f;
  NT2_TEST_EQUAL( f , 13.37f );
}
