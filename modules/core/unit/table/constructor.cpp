//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 core - table constructors test"

//==============================================================================
// Test behavior of nt2::container::extent
//==============================================================================
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/toolbox/operator.hpp>
#include <nt2/core/container/table.hpp>
#include <nt2/toolbox/constant/constants/dsl/digits.hpp>

NT2_TEST_CASE_TPL( default_dynamic_ctor, NT2_TYPES )
{
  using nt2::table;

  table<T> x;
  NT2_TEST( x.empty() );
  NT2_TEST_EQUAL( x.size()  , 0 );

  NT2_TEST_EQUAL( x.lower(1) , 0  );
  NT2_TEST_EQUAL( x.upper(1) , -1 );
  NT2_TEST_EQUAL( x.lower(2) , 0  );
  NT2_TEST_EQUAL( x.upper(2) , 0  );
  NT2_TEST_EQUAL( x.lower(3) , 0  );
  NT2_TEST_EQUAL( x.upper(3) , 0  );
  NT2_TEST_EQUAL( x.lower(4) , 0  );
  NT2_TEST_EQUAL( x.upper(4) , 0  );

}

NT2_TEST_CASE_TPL( default_static_ctor, NT2_TYPES )
{
  using nt2::table;
  using nt2::of_size_;

  table<T, of_size_<2,3,4,5> > x;

  NT2_TEST( !x.empty()      );
  NT2_TEST_EQUAL( x.size()  , 120 );

  NT2_TEST_EQUAL( x.lower(1) , 1  );
  NT2_TEST_EQUAL( x.upper(1) , 2 );
  NT2_TEST_EQUAL( x.lower(2) , 1  );
  NT2_TEST_EQUAL( x.upper(2) , 3  );
  NT2_TEST_EQUAL( x.lower(3) , 1  );
  NT2_TEST_EQUAL( x.upper(3) , 4  );
  NT2_TEST_EQUAL( x.lower(4) , 1  );
  NT2_TEST_EQUAL( x.upper(4) , 5  );
}

