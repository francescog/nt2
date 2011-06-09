/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::shift_left"

#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/include/functions/shift_left.hpp>
#include <boost/type_traits/is_same.hpp>

#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/module.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test behavior for shift_left
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL ( shift_left, NT2_INTEGRAL_TYPES )
{
  using boost::is_same;
  using nt2::tag::shift_left_;

  NT2_TEST( (boost::is_same < typename nt2::meta::call<shift_left_(T,T)>::type
                            , BOOST_TYPEOF(T() << T())
                            >::value
            )
          );

  NT2_TEST_EQUAL( nt2::shift_left(1,2) , 1 << 2 );
}

////////////////////////////////////////////////////////////////////////////////
// Test behavior for shift_left on real
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE( shift_left_real )
{
  using boost::is_same;
  using nt2::tag::shift_left_;

  NT2_TEST( (boost::is_same < nt2::meta::call<shift_left_(double,int)>::type
                            , double
                            >::value
            )
          );
  NT2_TEST( (boost::is_same < nt2::meta::call<shift_left_(float,int)>::type
                            , float
                            >::value
            )
          );

  NT2_TEST_EQUAL( nt2::shift_left(0.5f, 1 ), 4.253529586511731e+37    );
  NT2_TEST_EQUAL( nt2::shift_left(1.  , 1 ), 8.9884656743115800e+307  );
}
