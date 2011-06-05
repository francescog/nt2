/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DSL_FORWARD_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DSL_FORWARD_HPP_INCLUDED

namespace nt2 { namespace containers
{
  template<class Tag>                             struct grammar;
  template<class Expression>                      struct semantic;
  template<class Tag, class Dimension>            struct domain;
  template<class Tag, class Dimension>            struct generator;
  template<class AST,class Tag,class Dimensions>  struct container;
} }

#endif
