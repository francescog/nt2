/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_DSL_TERMINAL_OF_HPP_INCLUDED
#define NT2_SDK_DSL_TERMINAL_OF_HPP_INCLUDED

#include <boost/proto/traits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/sdk/dsl/compute.hpp>
#include <nt2/sdk/details/decltype.hpp>

////////////////////////////////////////////////////////////////////////////////
// If type is a proto expression, return the type obtained when evaluating it.
////////////////////////////////////////////////////////////////////////////////
namespace nt2
{
  namespace details
  {
    template<typename T>
    T& make();
  }
  
namespace meta
{
  template<class T, class Enable = void>
  struct terminal_of : meta::strip<T>
  {
  };
  
  template<class T>
  struct terminal_of<T, typename boost::enable_if< boost::proto::is_expr<T> >::type>
  {
    typedef compile< compute<boost::mpl::_1> > compiler;
    NT2_DECLTYPE(compiler()(details::make<T>()), type);
  };
  
} }

#endif
