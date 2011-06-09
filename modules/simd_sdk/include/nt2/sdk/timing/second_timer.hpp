/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_TIMING_SECOND_TIMER_HPP_INCLUDED
#define BOOST_SIMD_SDK_TIMING_SECOND_TIMER_HPP_INCLUDED

#include <nt2/simd_sdk/timing/tic.hpp>

namespace boost { namespace time
{
  struct second_timer
  {
     second_timer(double& e, bool d = true) : elapsed(e), display(d) { tic(); }
    ~second_timer () { elapsed = toc(display); }

    double& elapsed;
    bool display;
  };
} }

#endif