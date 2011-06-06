/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_SIMD_PACK_META_DOWNGRADE_HPP_INCLUDED
#define NT2_SDK_SIMD_PACK_META_DOWNGRADE_HPP_INCLUDED

#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/simd/pack/forward.hpp>

namespace nt2
{
    namespace details { namespace simd
    {
        template<typename T, typename U>
        struct downgrade;
        
        template< class Type
                , std::size_t Cardinal
                >
        struct downgrade< nt2::simd::pack<Type, Cardinal>, Type >
        {
            typedef nt2::simd::pack<Type, Cardinal> type;
        };
        
        template< class Type
                , std::size_t Cardinal
                , class DownType
                >
        struct downgrade< nt2::simd::pack<Type, Cardinal>, DownType >
        {
            typedef nt2::simd::pack<DownType, Cardinal*2> type;
        };
    } }
    
    namespace meta
    {
        template< class Type
                , std::size_t Cardinal
                >
        struct downgrade< simd::pack<Type, Cardinal> >
        {
            typedef typename nt2::details::simd::downgrade<
                simd::pack<Type, Cardinal>
              , typename downgrade<Type>::type
            >::type type;
        };
    }
}

#endif
