/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_DIGITS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_DIGITS_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// List all basic -10,-9,...,0,...,10,100,1000 constants
////////////////////////////////////////////////////////////////////////////////
#include <boost/simd/include/simd.hpp>
#include <boost/simd/sdk/constant/constant.hpp>
#include <boost/simd/toolbox/constant/include.hpp>
#include <boost/simd/sdk/constant/common.hpp>

////////////////////////////////////////////////////////////////////////////////
// Constant tag
////////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace tag
{
  template<nt2::int64_t N> struct digit_ {};
} } }

////////////////////////////////////////////////////////////////////////////////
// Natural numbers between -10 and 10
////////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd
{
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<-10> , Mten  )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<-9 > , Mnine )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<-8 > , Meight)
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<-7 > , Mseven)
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<-6 > , Msix  )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<-5 > , Mfive )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<-4 > , Mfour )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<-3 > , Mthree)
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<-2 > , Mtwo  )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<-1 > , Mone  )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 0 > , Zero  )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 1 > , One   )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 2 > , Two   )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 3 > , Three )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 4 > , Four  )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 5 > , Five  )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 6 > , Six   )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 7 > , Seven )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 8 > , Eight )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 9 > , Nine  )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 10> , Ten   )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 20> , Twenty)

  ////////////////////////////////////////////////////////////////////////////////
  // Larger values
  ////////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 100> , Hundred  )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<1000> , Thousand )

  ////////////////////////////////////////////////////////////////////////////////
  // Values useful for trigo and what not
  ////////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 45> , Fortyfive         )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 90> , Ninety            )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<180> , Onehundredeighty  )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<180> , C_180             )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 45> , _45               )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_< 90> , _90               )
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::digit_<180> , _180              )

  ////////////////////////////////////////////////////////////////////////////////
  // Local digit based constant generator
  ////////////////////////////////////////////////////////////////////////////////
  template<class Target, nt2::int64_t N> inline
  typename meta::enable_call<tag::digit_<N>(meta::as_<Target>)>::type
  integral_constant()
  {
    boost::simd::functor< tag::digit_<N> > callee;
    return callee( boost::simd::meta::as_<Target>() );
  }
} }

#include <boost/simd/toolbox/constant/constants/scalar/digits.hpp>
#include <boost/simd/toolbox/constant/constants/simd/all/digits.hpp>

#endif
