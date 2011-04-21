/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DSL_DOMAIN_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DSL_DOMAIN_HPP_INCLUDED

#include <nt2/sdk/error/static_assert.hpp>

////////////////////////////////////////////////////////////////////////////////
// basic domain for all container to be specialized
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace container
{
  template<class Tag, class Dimension>
  struct  domain
  {
    NT2_STATIC_ASSERT ( (sizeof(Tag) != 0)
                      , NT2_STATIC_UNKNOWN_CONTAINER_TYPE
                      , "Container(s) with an undefined domain tag has been "
                        "used. Please check for typos or missing include in "
                        "your custom container definition."
                      );
  };
} }

#endif
