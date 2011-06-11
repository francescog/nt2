//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_DSL_EVALUATION_HPP_INCLUDED
#define NT2_SDK_DSL_EVALUATION_HPP_INCLUDED

#include <nt2/sdk/functor/functor.hpp>

namespace nt2
{
  namespace tag { struct evaluate_ {}; }

  //============================================================================
  /*!
   * Perform the evaluation of a given expression \c Xpr into some terminal
   * \c Term over a given architectural \c Target
   *
   * \taparam Target tag of evaluation target to use
   * \param term Terminal class receiving the values of xpr
   * \param xpr Expression to evaluate into term
   */
  //============================================================================
  template<class Target, class Term, class Xpr> inline
  typename meta::enable_call<tag::evaluate_(Term&, Xpr const&), Target>::type
  evaluate( Term& dst, Xpr const& xpr)
  {
    functor<tag::evaluate_,Target> callee;
    return callee(dst,xpr);
  }
}

#endif
