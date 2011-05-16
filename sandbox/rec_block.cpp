#include <iostream>
#include <nt2/core/container/table.hpp>
#include <nt2/core/functions/of_size.hpp>
#include <nt2/core/functions/size.hpp>

using namespace std;

//struct foo {float x; double y; };
//NT2_ADAPT_COMPOSITE(foo, (float, x)(double, y));

using nt2::container::table;

int main()
{
  {
    table<float, nt2::of_size_<3,4,1> > b1;//( nt2::of_size(3,4,1) );
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
