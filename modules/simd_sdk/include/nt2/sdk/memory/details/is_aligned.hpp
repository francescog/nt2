/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_MEMORY_DETAILS_IS_ALIGNED_HPP_INCLUDED
#define BOOST_SIMD_SDK_MEMORY_DETAILS_IS_ALIGNED_HPP_INCLUDED

#include <nt2/simd_sdk/meta/mpl.hpp>
#include <nt2/simd_sdk/memory/parameters.hpp>
#include <nt2/simd_sdk/memory/meta/is_aligned.hpp>
#include <nt2/simd_sdk/memory/details/category.hpp>
#include <nt2/simd_sdk/functor/preprocessor/call.hpp>

////////////////////////////////////////////////////////////////////////////////
// Check alignment of integer on integer
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::is_aligned_, tag::cpu_
                             , (A0)(A1)      , (integer_<A0>)(integer_<A1>)
                             )

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::is_aligned_( tag::integer_, tag::integer_), tag::cpu_, Dummy>
        : callable
  {
    typedef bool result_type;
    BOOST_SIMD_FUNCTOR_CALL(2) { return !(a0 & (a1-1) ); }
  };
} } }

////////////////////////////////////////////////////////////////////////////////
// Check alignment of integer on mpl integer
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::is_aligned_, tag::cpu_
                             , (A0)(A1), (integer_<A0>)(mpl_integral_< integer_<A1> >)
                             )

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::is_aligned_( tag::integer_
                                , tag::mpl_integral_<tag::integer_>
                                )
              , tag::cpu_, Dummy
              >
        : callable
  {
    typedef bool result_type;
    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      ignore_unused(a1);
      return !(a0 & (A1::value-1) );
    }
  };
} } }

////////////////////////////////////////////////////////////////////////////////
// Check alignment of integer on default alignment
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::is_aligned_, tag::cpu_, (A0), (integer_<A0>) )

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::is_aligned_( tag::integer_), tag::cpu_, Dummy >
        : callable
  {
    typedef bool result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return boost::simd::memory::is_aligned<BOOST_SIMD_CONFIG_ALIGNMENT>(a0);
    }
  };
} } }

////////////////////////////////////////////////////////////////////////////////
// Check alignment of mpl integer on mpl integer
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::is_aligned_, tag::cpu_
                             , (A0)(A1)
                             , (mpl_integral_< integer_<A0> >)(mpl_integral_< integer_<A1> >)
                             )

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::is_aligned_( tag::mpl_integral_<tag::integer_>
                                , tag::mpl_integral_<tag::integer_>
                                )
              , tag::cpu_, Dummy
              >
        : callable
  {
    typedef bool result_type;

    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      ignore_unused(a0);
      ignore_unused(a1);
      return meta::is_aligned<A0,A1>::value;
    }
  };
} } }

////////////////////////////////////////////////////////////////////////////////
// Check alignment of mpl integer on default alignment
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::is_aligned_, tag::cpu_
                             , (A0), (mpl_integral_< integer_<A0> >)
                             )

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::is_aligned_(tag::mpl_integral_<tag::integer_>)
              , tag::cpu_, Dummy
              >
        : callable
  {
    typedef bool result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return boost::simd::memory::is_aligned<BOOST_SIMD_CONFIG_ALIGNMENT>(a0);
    }
  };
} } }

////////////////////////////////////////////////////////////////////////////////
// Check alignment of iterator on integer
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::is_aligned_, tag::cpu_
                             , (A0)(A1)      , (iterator_<unspecified_<A0> >)(integer_<A1>)
                             )

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::is_aligned_( tag::iterator_<tag::unspecified_>
                                , tag::integer_
                                )
              , tag::cpu_, Dummy
              >
        : callable
  {
    typedef bool result_type;

    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      return boost::simd::memory::is_aligned( reinterpret_cast<std::size_t>(a0), a1 );
    }
  };
} } }

////////////////////////////////////////////////////////////////////////////////
// Check alignment of iterator on mpl integer
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::is_aligned_, tag::cpu_
                             , (A0)(A1)
                             , (iterator_<unspecified_<A0> >)(mpl_integral_< integer_<A1> >)
                             )

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::is_aligned_( tag::iterator_<tag::unspecified_>
                                , tag::mpl_integral_<tag::integer_>
                                )
              , tag::cpu_, Dummy
              >
        : callable
  {
    typedef bool result_type;

    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      return boost::simd::memory::is_aligned( reinterpret_cast<std::size_t>(a0), a1 );
    }
  };
} } }

////////////////////////////////////////////////////////////////////////////////
// Check alignment of iterator on default alignment
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH(tag::is_aligned_,tag::cpu_,(A0),(iterator_<unspecified_<A0> >))

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::is_aligned_(tag::iterator_<tag::unspecified_>)
              , tag::cpu_, Dummy
              >
        : callable
  {
    typedef bool result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return boost::simd::memory::is_aligned<BOOST_SIMD_CONFIG_ALIGNMENT>(a0);
    }
  };
} } }

#endif