//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_IO_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_IO_HPP_INCLUDED

/*!
 * \file
 * Implements stream insertion for \ref extent
 */

#include <boost/fusion/include/io.hpp>
#include <boost/fusion/include/as_vector.hpp>

namespace nt2 { namespace containers
{
  //============================================================================
  /*!
   * \ingroup containerhelper
   *
   * Send a textual representation of an \extent to an output stream.
   *
   * \param os Output stream
   * \param e  Extent to stream
   *
   * \return The modified output stream
   */
  //============================================================================
  template<class AST, class D> inline
  std::ostream& operator<<( std::ostream& os
                          , container<AST,tag::extent_,D> const& e
                          )
  {
    os << "( ";
    for(std::size_t i=1;i<=e.size();++i) os << e(i) << " ";
    os << ")";
    return os;
  }
} }

#endif
