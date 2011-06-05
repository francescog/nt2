//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_SEMANTIC_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_SEMANTIC_HPP_INCLUDED

//==============================================================================
// Additional common semantic on extent expressions
//==============================================================================
namespace nt2 { namespace containers
{
  template<class AST, class Dimensions>
  struct  semantic< container<AST, tag::extent_, Dimensions> >
  {
    typedef tag::extent_                                 fusion_tag;
  };
} }

#endif
