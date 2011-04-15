/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_SETTINGS_PADDING_HPP_INCLUDED
#define NT2_CORE_SETTINGS_PADDING_HPP_INCLUDED

#include <nt2/sdk/memory/no_padding.hpp>
#include <nt2/sdk/memory/lead_padding.hpp>
#include <nt2/sdk/memory/global_padding.hpp>
#include <nt2/core/settings/meta/option.hpp>

////////////////////////////////////////////////////////////////////////////////
// Defines padding_ options
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace options
{
  struct padding_ { typedef void nt2_is_option_type; };
} }

////////////////////////////////////////////////////////////////////////////////
// Various basic padding strategies
////////////////////////////////////////////////////////////////////////////////
namespace nt2
{
  struct no_padding_      { typedef memory::no_padding      type; };
  struct lead_padding_    { typedef memory::lead_padding    type; };
  struct global_padding_  { typedef memory::global_padding  type; };
}

////////////////////////////////////////////////////////////////////////////////
// Register padding strategies as valid options::padding_ type
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  template<class Default>
  struct option<no_padding_, options::padding_, Default, void>
  {
    typedef no_padding_ type;
  };

  template<class Default>
  struct option<lead_padding_, options::padding_, Default, void>
  {
    typedef lead_padding_ type;
  };

  template<class Default>
  struct option<global_padding_, options::padding_, Default, void>
  {
    typedef global_padding_ type;
  };
} }

#endif
