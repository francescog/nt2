//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 core - extent fusion support test"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of nt2::container::extent
//////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/core/container/extent.hpp>

#include <boost/fusion/include/empty.hpp>

#define M0(z,n,t) (nt2::BOOST_PP_CAT(BOOST_PP_CAT(_,n),D))
#define DYN_DIM_LIST BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M0,~)

NT2_TEST_CASE ( fusion_random_access_sequence_0d )
{
  using nt2::extent;

  extent<nt2::_0D> x;
  //NT2_TEST( boost::fusion::empty(x) );

  nt2::display_type( nt2::size(x) );
  nt2::display_type( nt2::size(x+x) );

  /*
  NT2_TEST_EQUAL( x.size()  , 0);
  NT2_TEST_EQUAL( x.size(0) , 1);
  NT2_TEST_EQUAL( x.lower(0), 1);
  NT2_TEST_EQUAL( x.upper(0), 1);
  NT2_TEST_EQUAL( x.nDims() , 0);
  NT2_TEST_EQUAL( x(1)      , 1);
*/
/*
 * begin(s)
end(s)
size(s)
empty(s)
front(s)
front(s) = o
back(s)
back(s) = o
at<N>(s)
at<N>(s) = o
 *
 */
}

NT2_TEST_CASE_TPL ( fusion_random_access_sequence, DYN_DIM_LIST )
{
  using nt2::extent;

}
