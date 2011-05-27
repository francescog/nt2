/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DSL_GENERATOR_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DSL_GENERATOR_HPP_INCLUDED

#include <nt2/sdk/error/assert.hpp>
#include <nt2/sdk/error/static_assert.hpp>

namespace nt2 { namespace containers
{
  //////////////////////////////////////////////////////////////////////////////
  // Container Expression check if their size are compatible before being built
  // Depending on tag and types, a static or runtime assertion can be triggered
  //////////////////////////////////////////////////////////////////////////////
  template<class Tag, class Dimension> struct generator;
} }

#endif
