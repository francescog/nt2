//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DSL_FORWARD_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DSL_FORWARD_HPP_INCLUDED

/*!
 * \file
 * \brief Defines the containers DSL extension points
 */

namespace nt2 { namespace containers
{
  template<class Tag>                             struct grammar;
  template<class Tag, class Dimension>            struct domain;
  template<class Tag, class Dimension>            struct generator;
  template<class AST,class Tag,class Dimensions>  struct container;
} }

#endif
