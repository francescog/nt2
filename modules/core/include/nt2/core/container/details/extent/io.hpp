/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_IO_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_IO_HPP_INCLUDED

#include <boost/fusion/include/io.hpp>
#include <boost/fusion/include/as_vector.hpp>

namespace nt2 { namespace container
{
  template<class D> inline
  std::ostream& operator<<( std::ostream& os, extent<D> const& e )
  {
    return os << "(" << boost::fusion::as_vector(e.data()) << ")";
  }
} }

#endif
