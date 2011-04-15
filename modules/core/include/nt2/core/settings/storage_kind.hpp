/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_SETTINGS_STORAGE_KIND_HPP_INCLUDED
#define NT2_CORE_SETTINGS_STORAGE_KIND_HPP_INCLUDED

#include <boost/mpl/identity.hpp>
#include <nt2/core/settings/meta/option.hpp>

////////////////////////////////////////////////////////////////////////////////
// Defines storage_kind_ options
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace options
{
  struct storage_kind_ { typedef void nt2_is_option_type; };
} }

////////////////////////////////////////////////////////////////////////////////
// Various basic storage kind
////////////////////////////////////////////////////////////////////////////////
namespace nt2
{
  struct heap_  { typedef heap_   type; };
  struct stack_ { typedef stack_  type; };
}

////////////////////////////////////////////////////////////////////////////////
// Register heap_ and stack_ as valid options::storage_kind_ type
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  template<class Default>
  struct option<heap_, options::storage_kind_, Default, void>
  {
    typedef heap_ type;
  };

  template<class Default>
  struct option<stack_, options::storage_kind_, Default, void>
  {
    typedef stack_ type;
  };
} }

#endif
