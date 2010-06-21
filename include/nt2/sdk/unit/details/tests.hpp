/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_UNIT_DETAILS_TESTS_HPP_INCLUDED
#define NT2_SDK_UNIT_DETAILS_TESTS_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Helpers for building impelmentation fo some predicate based tests
////////////////////////////////////////////////////////////////////////////////
#define NT2_MAKE_TEST_FUNC(NAME,OP,COP)                                         \
  template<class T, class U>                                                    \
  inline void NAME( char const* x1, char const* x2                              \
                  , int line, char const * fn                                   \
                  , T const & t, U const & u                                    \
                  )                                                             \
  {                                                                             \
    test_count()++;                                                             \
    if( t OP u )                                                                \
    {                                                                           \
      std::cout << "  Test '"                                                   \
                << x1 << " " << #OP << " " << x2                                \
                << "' passed." << std::endl;                                    \
    }                                                                           \
    else                                                                        \
    {                                                                           \
      std::cout << "  Test '"<< x1 << " "<< #OP << " " << x2                    \
                << "' failed in function " << fn << " (" << line << ")"  \
                << ":  '" << t << " "<< #COP << " " << u << "'"                 \
                << std::endl;                                                   \
      ++error_count();                                                          \
    }                                                                           \
  }                                                                             \
/**/

namespace nt2 { namespace details
{
  NT2_MAKE_TEST_FUNC(test_eq  , ==, !=  )
  NT2_MAKE_TEST_FUNC(test_neq , !=, ==  )
  NT2_MAKE_TEST_FUNC(test_lt  , < , >=  )
  NT2_MAKE_TEST_FUNC(test_gt  , > , <=  )
  NT2_MAKE_TEST_FUNC(test_le  , <= , >  )
  NT2_MAKE_TEST_FUNC(test_ge  , >= , <  )
} }

#endif