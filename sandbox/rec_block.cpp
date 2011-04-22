#include <iostream>
#include <nt2/core/container/table.hpp>
#include <nt2/core/functions/of_size.hpp>
#include <nt2/core/functions/size.hpp>

using namespace std;

struct foo {float x; double y; };

NT2_ADAPT_COMPOSITE(foo, (float, x)(double, y));

using nt2::container::block;

int main()
{
  nt2::table<foo, nt2::C_index_> xd( nt2::of_size(2,2) );

  std::cout << xd.empty() << "\n";
  std::cout << xd.size() << "\n";
  std::cout << xd.size<1>() << " " << xd.lower<1>() << " " << xd.upper<1>() << "\n";
  std::cout << xd.size<2>() << " " << xd.lower<2>() << " " << xd.upper<2>() << "\n";
  std::cout << xd.size<3>() << " " << xd.lower<3>() << " " << xd.upper<3>() << "\n";
  std::cout << xd.size<4>() << " " << xd.lower<4>() << " " << xd.upper<4>() << "\n";

  std::cout << nt2::size(8.f)(1) << "\n";
  std::cout << nt2::size(8.f)(2) << "\n";
}
