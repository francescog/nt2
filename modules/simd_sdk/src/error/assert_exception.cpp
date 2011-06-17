//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================

#include <iostream>
#include <boost/simd/sdk/error/assert.hpp>

#if !defined(BOOST_SIMD_NO_EXCEPTIONS)

namespace boost
{
  namespace simd
  {
    void assert_exception::display(std::ostream& os) const throw()
    {
      os  << "Assertion: "
	  << *boost::get_error_info<nt2::details::assert_info>(*this)
	  << " failed.\n";
    }
  }
}

#endif
