#include <iostream>
#include <nt2/sdk/details/type_id.hpp>

#include <boost/fusion/include/make_vector.hpp>
#include <boost/fusion/include/vector_tie.hpp>
#include <nt2/sdk/memory/lead_padding.hpp>

#include <nt2/core/container/details/block.hpp>
#include <nt2/core/container/table.hpp>

using namespace std;

struct foo {float x; double y; };

NT2_ADAPT_COMPOSITE(foo, (float, x)(double, y));

using nt2::container::block;

int main()
{
  {
    typedef block < float
                  , boost::mpl::int_<1>
                  , boost::mpl::vector_c<int,9>
                  , boost::array<int,1>
                  , boost::mpl::vector_c<int,0>
                  , nt2::heap_(nt2::memory::allocator<float>)
                  , nt2::memory::lead_padding
                  > t_t;

    boost::array<int,1> sz= {{5}};
    boost::mpl::vector_c<int,9> bz;
    t_t  t(bz,sz);

    cout << t( boost::fusion::make_vector(t.lower<1>()) ) << "\n";
    t( boost::fusion::make_vector(t.lower<1>()) ) = 9.999f;
    cout << t( boost::fusion::make_vector(t.lower<1>()) ) << "\n";

    cout << t.size() << "\n";
    cout  << t.lower<1>()
          << " " << t.upper<1>()
          << " " << t.size<1>()
          << "\n";
  }

  {
    typedef block < float
                  , boost::mpl::int_<2>
                  , boost::mpl::vector_c<int,3,1>
                  , boost::array<int,2>
                  , boost::mpl::vector_c<int,0,1>
                  , nt2::heap_(nt2::memory::allocator<float>)
                  , nt2::memory::lead_padding
                  > t_t;
    boost::array<int,2> sz= {{5,3}};
    boost::mpl::vector_c<int,3,1> bz;
    t_t  t(bz,sz);

    cout << t( boost::fusion::make_vector(t.lower<1>(),t.lower<2>()) ) << "\n";
    t( boost::fusion::make_vector(t.lower<1>(),t.lower<2>()) ) = 9.999f;
    cout << t( boost::fusion::make_vector(t.lower<1>(),t.lower<2>()) ) << "\n";

    cout << t.size() << "\n";
    cout  << t.lower<1>()
          << " " << t.upper<1>()
          << " " << t.size<1>()
          << "\n";
    cout  << t.lower<2>()
          << " " << t.upper<2>()
          << " " << t.size<2>()
          << "\n";
  }
  {
    typedef block < float
                  , boost::mpl::int_<2>
                  , boost::mpl::vector_c<int,3,1>
                  , boost::array<int,2>
                  , boost::mpl::vector_c<int,1,0>
                  , nt2::heap_(nt2::memory::allocator<float>)
                  , nt2::memory::lead_padding
                  > t_t;
    boost::array<int,2> sz= {{5,3}};
    boost::mpl::vector_c<int,3,1> bz;
    t_t  t(bz,sz);

    cout << t( boost::fusion::make_vector(t.lower<1>(),t.lower<2>()) ) << "\n";
    t( boost::fusion::make_vector(t.lower<1>(),t.lower<2>()) ) = 9.999f;
    cout << t( boost::fusion::make_vector(t.lower<1>(),t.lower<2>()) ) << "\n";

    cout << t.size() << "\n";
    cout  << t.lower<1>()
          << " " << t.upper<1>()
          << " " << t.size<1>()
          << "\n";
    cout  << t.lower<2>()
          << " " << t.upper<2>()
          << " " << t.size<2>()
          << "\n";
  }

  {
    typedef block < foo
                  , boost::mpl::int_<1>
                  , boost::mpl::vector_c<int,0>
                  , boost::array<int,1>
                  , boost::mpl::vector_c<int,0>
                  , nt2::heap_(nt2::memory::allocator<foo>)
                  , nt2::memory::lead_padding
                  > t_t;
    boost::array<int,1> sz= {{5}};
    boost::mpl::vector_c<int,0> bz;
    t_t  t(bz,sz);

    cout << t.size() << "\n";
    cout  << t.lower<1>()
          << " " << t.upper<1>()
          << " " << t.size<1>()
          << "\n";
  }

  {
    typedef block < foo
                   , boost::mpl::int_<2>
                   , boost::mpl::vector_c<int,0,0>
                   , boost::array<int,2>
                   , boost::mpl::vector_c<int,0,1>
                   , nt2::heap_(nt2::memory::allocator<foo>)
                   , nt2::memory::lead_padding
                   > t_t;
     boost::array<int,2> sz= {{5,7}};
     boost::mpl::vector_c<int,0,0> bz;
     t_t  t(bz,sz);

     cout << t.size() << "\n";
     cout  << t.lower<1>()
           << " " << t.upper<1>()
           << " " << t.size<1>()
           << "\n";
  }
}
