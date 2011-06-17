//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_FUNCTOR_DETAILS_CALL_HPP_INCLUDED
#define BOOST_SIMD_SDK_FUNCTOR_DETAILS_CALL_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// User-overloadable call meta-function
// Documentation:http://nt2.lri.fr/extension/custom_function.html
////////////////////////////////////////////////////////////////////////////////
#include <boost/type_traits/is_same.hpp>
#include <boost/simd/sdk/error/static_assert.hpp>

////////////////////////////////////////////////////////////////////////////////
// Forward declare the unknown_ tag and the error_with helper
////////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace tag { struct unknown_;    } } }
namespace boost { namespace simd {  namespace tag { struct error_with;  } } }

namespace boost { namespace simd { namespace ext
{
  //////////////////////////////////////////////////////////////////////////////
  // Flag call instanciation as callable
  //////////////////////////////////////////////////////////////////////////////
  struct callable { typedef void callable_type; };

  //////////////////////////////////////////////////////////////////////////////
  // Call to non-categorizable types ends up in error
  //////////////////////////////////////////////////////////////////////////////
  template<class Function,class Site,class Dummy>
  struct call<Function(tag::unknown_),Site,Dummy>
  {
    typedef int result_type;
    BOOST_SIMD_STATIC_ASSERT ( (boost::is_same<Function,void>::value)
                      , BOOST_SIMD_UNSUPPORTED_FUNCTION_CALL
                      , "If you get an error here, you tried to call a nt2 "
                        "function on values which types is not supported by nt2 "
                        "or which is not implemented on the given type. "
                        "Check that you included the proper toolbox or use the "
                        "correct type in your function call."
                      );
  };
} }}

#endif
