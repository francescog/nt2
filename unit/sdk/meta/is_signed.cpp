/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::meta::is_signed"

#include <nt2/sdk/meta/is_signed.hpp>
#include <nt2/sdk/functor/category.hpp>

#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test that is_signed is correct
////////////////////////////////////////////////////////////////////////////////
struct foo {};

NT2_TEST_CASE(is_signed)
{
  using nt2::meta::is_signed;
  using namespace nt2;

  NT2_TEST( is_signed<double>::value    );
  NT2_TEST( is_signed<float>::value     );
  NT2_TEST( !is_signed<uint64_t>::value );
  NT2_TEST( !is_signed<uint32_t>::value );
  NT2_TEST( !is_signed<uint16_t>::value );
  NT2_TEST( !is_signed<uint8_t>::value  );
  NT2_TEST( is_signed<int64_t>::value   );
  NT2_TEST( is_signed<int32_t>::value   );
  NT2_TEST( is_signed<int16_t>::value   );
  NT2_TEST( is_signed<int8_t>::value    );
  NT2_TEST( !is_signed<bool>::value     );
  NT2_TEST( !is_signed<foo>::value      );
}