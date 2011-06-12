//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 core - nbdims test"

//==============================================================================
// Test behavior of nt2::nbdims
//==============================================================================
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/core/functions/nbdims.hpp>
#include <nt2/core/container/extent.hpp>

#define M0(z,n,t) (nt2::BOOST_PP_CAT(BOOST_PP_CAT(_,n),D))
#define DYN_DIM_LIST BOOST_PP_REPEAT(BOOST_PP_INC(NT2_MAX_DIMENSIONS),M0,~)

NT2_TEST_CASE ( nbdims_scalar )
{
  using nt2::nbdims;

  NT2_TEST_EQUAL( nbdims(13.37), 0 );
}

NT2_TEST_CASE_TPL ( nbdims_extents, DYN_DIM_LIST )
{
  using nt2::nbdims;
  using nt2::extent;

  extent<T> x;
  NT2_TEST_EQUAL( nbdims(x), 2 );
}
