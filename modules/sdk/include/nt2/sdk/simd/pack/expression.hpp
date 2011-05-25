/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_SIMD_PACK_EXPRESSION_HPP_INCLUDED
#define NT2_SDK_SIMD_PACK_EXPRESSION_HPP_INCLUDED

#include <nt2/sdk/dsl/category.hpp>
#include <nt2/sdk/dsl/proto/extends.hpp>
#include <nt2/sdk/simd/meta/extension_of.hpp>
#include <nt2/sdk/dsl/terminal_of.hpp>

namespace nt2
{
  template<class Expr, class Enable = void>
  struct evaluate
  {
    typedef typename meta::terminal_of<Expr>::type result_type;
    result_type operator()(Expr const& expr) const
    {
      return meta::compile< meta::compute<boost::mpl::_1> >()(expr);
    }
  };
  
  template<class Expr>
  struct evaluate<Expr, typename meta::enable_if_type< typename meta::terminal_of<Expr>::type::parent >::type>
  {
    typedef typename meta::terminal_of<Expr>::type result_type;
    result_type operator()(Expr const& expr) const
    {
      result_type that;
      that = expr;
      return that;
    }
  };
  
namespace simd
{
  ////////////////////////////////////////////////////////////////////////////
  // Here is the domain-specific expression wrapper
  ////////////////////////////////////////////////////////////////////////////
  template<class Expr,class Type,class Cardinal>
  struct  expression
        : boost::proto::extends < Expr
                                , expression<Expr,Type,Cardinal>
                                , domain<Type,Cardinal>
                                >
  {
    ////////////////////////////////////////////////////////////////////////////
    // expression hierarchy of simd:::expression
    ////////////////////////////////////////////////////////////////////////////
    typedef typename
    details::hierarchy_of_expr<expression>::type nt2_hierarchy_tag;

    ////////////////////////////////////////////////////////////////////////////
    // FusionRandomAccessSequence interface
    ////////////////////////////////////////////////////////////////////////////
    typedef data<Type,Cardinal>                     data_type;
    typedef typename data_type::value_type          value_type;
    typedef typename data_type::reference           reference;
    typedef typename data_type::const_reference     const_reference;
    typedef typename data_type::size_type           size_type;
    typedef typename data_type::iterator            iterator;
    typedef typename data_type::const_iterator      const_iterator;

    typedef boost::proto::extends<Expr,expression,domain<Type,Cardinal> > parent;

    expression( Expr const& xpr = Expr() ) : parent(xpr) {}

    ////////////////////////////////////////////////////////////////////////////
    // Array interface
    ////////////////////////////////////////////////////////////////////////////
    BOOST_STATIC_CONSTANT(size_type, static_size = Cardinal::value);
    
    typedef typename meta::terminal_of<expression>::type eval_type;
    
    eval_type evaluate() const
    {
      return nt2::evaluate<expression>()(*this);
    }
    
    operator eval_type() const
    {
      return evaluate();
    }
    
    ////////////////////////////////////////////////////////////////////////////
    // Range interface
    ////////////////////////////////////////////////////////////////////////////
    const_iterator  begin()  const
    {
      return evaluate().begin();
    }

    const_iterator  end()    const
    {
      return evaluate().end();
    }

    ////////////////////////////////////////////////////////////////////////////
    // Extract element
    ////////////////////////////////////////////////////////////////////////////
    const_reference operator[](int i)     const
    {
      return evaluate()[i];
    }
  };
  
  // Do all operators?
  template<class T, class Expr>
  struct left_shift_impl
  {
    typedef __typeof__(details::make<T>() << details::make<typename meta::terminal_of<Expr>::type>())& result_type;
    
    result_type operator()(T& lft, Expr const& expr) const
    {
      return lft << expr.evaluate();
    }
  };
  
  template<class T, class Expr, class Type, class Cardinal>
  typename left_shift_impl<T, expression<Expr, Type, Cardinal> >::result_type
  operator<<(T& lft, expression<Expr, Type, Cardinal> const& rgt)
  {
    return left_shift_impl<T, expression<Expr, Type, Cardinal> >()(lft, rgt);
  }
  
} }

#endif
