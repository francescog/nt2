/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::shift_left SIMD"

#include <nt2/sdk/simd/native.hpp>
#include <nt2/include/functions/load.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/include/functions/shift_left.hpp>
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>

#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/module.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test behavior for shift_left
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL ( shift_left, NT2_SIMD_TYPES )
{
  using boost::is_same;
  using nt2::tag::shift_left_;
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  using nt2::meta::as_integer;

  typedef NT2_SIMD_DEFAULT_EXTENSION            ext_t;
  typedef native<T,ext_t>                       n_t;
  typedef typename as_integer<n_t>::type  i_t;

  NT2_TEST( (boost::is_same < typename nt2::meta::call<shift_left_(n_t,i_t)>::type
                            , n_t
                            >::value
            )
          );

  NT2_ALIGNED_TYPE(T) data[cardinal_of<n_t>::value];
  for(std::size_t i=0;i<cardinal_of<n_t>::value;++i)
    data[i] = 1+i;

  n_t v = nt2::load<n_t>(&data[0],0);
  i_t s = nt2::splat<i_t>(2);

  for(std::size_t j=0;j<cardinal_of<n_t>::value;++j)
  {
    NT2_TEST_EQUAL( (v << s)[j]              , nt2::shift_left(v[j],s[j]) );
    NT2_TEST_EQUAL( (nt2::shift_left(v,s))[j], nt2::shift_left(v[j],s[j]) );
  }
}

