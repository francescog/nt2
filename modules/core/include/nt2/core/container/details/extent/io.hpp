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

namespace nt2 { namespace container
{
  template<std::size_t D,class T> inline
  std::ostream& operator<<( std::ostream& os, extent<D,T> const& e )
  {
    os << "[ ";
    for(std::size_t i=1;i<=(D?D:1);++i) os << e(i) << " ";
    os << "]";
    return os;
  }
} }

#endif
