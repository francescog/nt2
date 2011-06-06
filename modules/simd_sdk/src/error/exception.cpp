//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================

#include <nt2/sdk/error/error.hpp>
#if !defined(NT2_DISABLE_ERROR)
#include <sstream>
#include <iostream>
#include <nt2/sdk/details/timestamp.hpp>

namespace nt2
{
  const char* exception::what() const throw()
  {
    std::ostringstream msg;
    msg << *this;
    return msg.str().c_str();
  }

  std::ostream& operator<<( std::ostream& os, exception const& e )
  {
    os
    << "****************************** NT2 ERROR *******************************\n"
    << "Raised: " << timestamp()                                      << "\n"
    << "File  : " << *boost::get_error_info<boost::throw_file>(e)     << "\n"
    << "Line  : " << *boost::get_error_info<boost::throw_line>(e)     << "\n"
    << "In    : " << *boost::get_error_info<boost::throw_function>(e) << "\n"
    << "************************************************************************\n";
    e.display(os);
    os
    << "************************************************************************\n";
    return os;
  }
}

#endif
