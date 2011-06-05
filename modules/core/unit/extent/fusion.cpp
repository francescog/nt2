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
#include <nt2/toolbox/operator.hpp>
#include <nt2/core/container/extent.hpp>

#include <boost/fusion/include/size.hpp>
#include <boost/fusion/include/empty.hpp>

#define M0(z,n,t) (nt2::BOOST_PP_CAT(BOOST_PP_CAT(_,n),D))
#define DYN_DIM_LIST BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M0,~)

NT2_TEST_CASE ( fusion_random_access_sequence_0d )
{
  using nt2::extent;
  extent<nt2::_0D> x;

  NT2_TEST( boost::fusion::empty(x) );
  NT2_TEST( boost::fusion::empty(x+x) );
  NT2_TEST_EQUAL( int(boost::fusion::size(x)), 0 );
  NT2_TEST_EQUAL( int(boost::fusion::size(x+x)), 0 );

/*
 * begin(s)
end(s)
front(s)
front(s) = o
back(s)
back(s) = o
at<N>(s)
at<N>(s) = o
 */
}


NT2_TEST_CASE_TPL ( fusion_random_access_sequence, DYN_DIM_LIST )
{
  using nt2::extent;
  extent<T> x;
  std::size_t dims = T::dimensions;

  NT2_TEST( !boost::fusion::empty(x)  );
  NT2_TEST( !boost::fusion::empty(x*x));
  NT2_TEST_EQUAL( int(boost::fusion::size(x))   , dims );
  NT2_TEST_EQUAL( int(boost::fusion::size(x-x)) , dims );
}
