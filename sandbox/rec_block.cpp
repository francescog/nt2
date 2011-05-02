#include <iostream>
#include <nt2/core/container/table.hpp>
#include <nt2/core/functions/of_size.hpp>
#include <nt2/core/functions/size.hpp>

using namespace std;

//struct foo {float x; double y; };
//NT2_ADAPT_COMPOSITE(foo, (float, x)(double, y));

using nt2::container::table;

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is an expression
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH ( tag::size_, tag::cpu_
                      , (A0)(S)
                      , ((block_< fundamental_<A0>,S>))
                      )

namespace nt2 { namespace ext
{
  template<class S, class Dummy>
  struct  call< tag::size_(tag::block_<tag::fundamental_,S>)
              , tag::cpu_, Dummy
              >
        : callable
  {
    template<class Sig> struct result;

    template<class This,class A0>
    struct result<This(A0)>
    {
      typedef typename meta::strip<A0>::type::sizes_type const& type;
    };

    NT2_FUNCTOR_CALL(1) { return a0.sizes(); }
  };
} }

int main()
{
  {
    table<float, nt2::_3D> b1( nt2::of_size(3,4,1) );
    table<float, nt2::_2D> b2( nt2::of_size(3,4) );
        using std::cout;

    cout << nt2::size(3.53f)     << "\n";
    cout << nt2::size(b1)     << "\n";
    cout << nt2::size(b1)     << "\n";
    cout << nt2::size(b1+b1)  << "\n";
    cout << nt2::size(b1+b2)  << "\n";
    cout << nt2::size(b2+b1)  << "\n";
    cout << nt2::size(b2+b2)  << "\n";
  }

}
