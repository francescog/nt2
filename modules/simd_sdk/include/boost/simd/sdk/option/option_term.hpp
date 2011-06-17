//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_SIMD_SDK_OPTION_OPTION_TERM_HPP_INCLUDED
#define BOOST_SIMD_SDK_OPTION_OPTION_TERM_HPP_INCLUDED

#include <boost/simd/sdk/option/option.hpp>
#include <boost/proto/core.hpp>

namespace boost { namespace simd { namespace details
{
  struct option_term
      : boost::proto::terminal< option< boost::proto::_ > >
  {};
} } }

#endif
