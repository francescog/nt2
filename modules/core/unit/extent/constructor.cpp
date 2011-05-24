//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 core - extent constructors test"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of nt2::container::extent
//////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/core/container/extent.hpp>

#define M0(z,n,t) (nt2::BOOST_PP_CAT(BOOST_PP_CAT(_,n),D))
#define DYN_DIM_LIST BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M0,~)

NT2_TEST_CASE ( default_ctor_0d )
{
  using nt2::extent;

  extent<nt2::_0D> x;

  NT2_TEST( !x.empty() );
  NT2_TEST_EQUAL( x.size()  , 1);
  NT2_TEST_EQUAL( x.size(0) , 1);
  NT2_TEST_EQUAL( x.lower(0), 1);
  NT2_TEST_EQUAL( x.upper(0), 1);
  NT2_TEST_EQUAL( x.nDims() , 0);
  NT2_TEST_EQUAL( x(1)      , 1);
}

NT2_TEST_CASE_TPL ( default_ctor, DYN_DIM_LIST )
{
  using nt2::extent;

  extent<T> x;
  std::size_t dims = T::dimensions;

  NT2_TEST( !x.empty() );
  NT2_TEST_EQUAL( x.size()  , dims  );
  NT2_TEST_EQUAL( x.size(0) , dims  );
  NT2_TEST_EQUAL( x.nDims() , dims  );

  NT2_TEST_EQUAL( x(1)      , 0     );
  NT2_TEST_EQUAL( x.size(1) , dims  );
  NT2_TEST_EQUAL( x.lower(1), 1     );
  NT2_TEST_EQUAL( x.upper(1), dims  );

  for(std::size_t i= 2; i<= dims;++i)
  {
    NT2_TEST_EQUAL( x(i)      , 1 );
    NT2_TEST_EQUAL( x.size(i) , 1 );
    NT2_TEST_EQUAL( x.lower(i), 1 );
    NT2_TEST_EQUAL( x.upper(i), 1 );
  }
}

NT2_TEST_CASE_TPL ( value_ctor, DYN_DIM_LIST )
{
  using nt2::extent;

  extent<T> x( NT2_PP_IOTA(1,NT2_MAX_DIMENSIONS));
  std::size_t dims = T::dimensions;

  NT2_TEST( !x.empty() );
  NT2_TEST_EQUAL( x.size()  , dims  );
  NT2_TEST_EQUAL( x.size(0) , dims  );
  NT2_TEST_EQUAL( x.nDims() , dims  );

  NT2_TEST_EQUAL( x(1)      , 1     );
  NT2_TEST_EQUAL( x.size(1) , dims  );
  NT2_TEST_EQUAL( x.lower(1), 1     );
  NT2_TEST_EQUAL( x.upper(1), dims  );

  for(std::size_t i= 2; i<= dims;++i)
  {
    NT2_TEST_EQUAL( x(i)      , i );
    NT2_TEST_EQUAL( x.size(i) , 1 );
    NT2_TEST_EQUAL( x.lower(i), 1 );
    NT2_TEST_EQUAL( x.upper(i), 1 );
  }
}


NT2_TEST_CASE_TPL ( copy_ctor, DYN_DIM_LIST )
{
  using nt2::extent;

 std::size_t dims = T::dimensions;

  // Test copying _0D in a non-0D extent
  extent<nt2::_0D> z;
  extent<T> w(z);

  NT2_TEST( !w.empty() );
  NT2_TEST_EQUAL( w.size()  , dims);
  NT2_TEST_EQUAL( w.size(0) , dims);
  NT2_TEST_EQUAL( w.lower(0), 1);
  NT2_TEST_EQUAL( w.upper(0), 1);
  NT2_TEST_EQUAL( w.nDims() , dims);
  NT2_TEST_EQUAL( w(1)      , 1);

  for(std::size_t i= 2; i<= dims;++i)
  {
    NT2_TEST_EQUAL( w(i)      , 1 );
    NT2_TEST_EQUAL( w.size(i) , 1 );
    NT2_TEST_EQUAL( w.lower(i), 1 );
    NT2_TEST_EQUAL( w.upper(i), 1 );
  }

  // Test copying _nD in a nD extent
  extent<T> y( NT2_PP_IOTA(1,NT2_MAX_DIMENSIONS));
  extent<T> x(y);

  NT2_TEST( !x.empty() );
  NT2_TEST_EQUAL( x.size()  , dims  );
  NT2_TEST_EQUAL( x.size(0) , dims  );
  NT2_TEST_EQUAL( x.nDims() , dims  );

  NT2_TEST_EQUAL( x(1)      , 1     );
  NT2_TEST_EQUAL( x.size(1) , dims  );
  NT2_TEST_EQUAL( x.lower(1), 1     );
  NT2_TEST_EQUAL( x.upper(1), dims  );

  for(std::size_t i= 2; i<= dims;++i)
  {
    NT2_TEST_EQUAL( x(i)      , i );
    NT2_TEST_EQUAL( x.size(i) , 1 );
    NT2_TEST_EQUAL( x.lower(i), 1 );
    NT2_TEST_EQUAL( x.upper(i), 1 );
  }
}
