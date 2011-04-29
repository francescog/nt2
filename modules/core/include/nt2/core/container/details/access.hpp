/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_ACCESS_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_ACCESS_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Macros set for generating proper operator() overloads with proper NT2_ASSERT
////////////////////////////////////////////////////////////////////////////////

#define NT2_ASSERT_ACCESS(n,t)                                                  \
NT2_ASSERT(     ( t >= this->lower(n) )                                         \
            &&  ( t <= this->upper(n) )                                         \
            && BOOST_PP_STRINGIZE(Element index is out-of-range on dimension n) \
          );                                                                    \
/**/

#endif
