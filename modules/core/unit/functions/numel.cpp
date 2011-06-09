//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 core - numel test"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of nt2::value_at with scalar in ref and cref scenarii
//////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/core/functions/numel.hpp>
#include <nt2/core/container/extent.hpp>

#define M0(z,n,t) (nt2::BOOST_PP_CAT(BOOST_PP_CAT(_,n),D))
#define DYN_DIM_LIST BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M0,~)

NT2_TEST_CASE ( numel_scalar )
{
  using nt2::numel;

  NT2_TEST_EQUAL( numel(13.37), 1 );
}

NT2_TEST_CASE ( numel_extent_0D )
{
  using nt2::numel;
  using nt2::extent;

  extent<nt2::_0D> x;
  NT2_TEST_EQUAL( numel(x), 2 );
}

NT2_TEST_CASE_TPL ( numel_extents, DYN_DIM_LIST )
{
  using nt2::numel;
  using nt2::extent;
  std::size_t dims = T::dimensions > 2 ? T::dimensions : 2;

  extent<T> x;
  NT2_TEST_EQUAL( numel(x), dims );
}
