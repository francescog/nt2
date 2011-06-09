/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_CONFIG_COMPILER_HPP_INCLUDED
#define BOOST_SIMD_SDK_CONFIG_COMPILER_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Architecture configuration headers
// Defines architecture symbols for architecture related variation point.
// Documentation: http://nt2.lri.fr/sdk/config/compiler.html
////////////////////////////////////////////////////////////////////////////////
#include <boost/config.hpp>
#include <boost/version.hpp>
#include <nt2/sdk/simd_config/bootstrap.hpp>

#include <nt2/sdk/simd_config/compiler/gcc_xml.hpp>
#include <nt2/extension/sdk/config/compiler.hpp>
#include <nt2/sdk/simd_config/compiler/gcc.hpp>
#include <nt2/sdk/simd_config/compiler/visualc.hpp>
#include <nt2/sdk/simd_config/compiler/none.hpp>

#endif
