#include <iostream>
#include <nt2/core/container/table.hpp>
#include <nt2/core/functions/of_size.hpp>
//#include <nt2/core/functions/size.hpp>

using namespace std;

//struct foo {float x; double y; };
//NT2_ADAPT_COMPOSITE(foo, (float, x)(double, y));

using nt2::container::table;

int main()
{
  {
    table<float> b1;

    using std::cout;

    cout << "4 : " << b1.nDims() << "\n";
    cout << b1.empty() << "\n";
    cout << b1.size() << " " << b1.size(0) << "\n";
    cout << b1.lower(1) << " " << b1.upper(1) << " " << b1.size(1) << "\n";
    cout << b1.lower(2) << " " << b1.upper(2) << " " << b1.size(2) << "\n";
    cout << b1.lower(3) << " " << b1.upper(3) << " " << b1.size(3) << "\n";
    cout << b1.lower(4) << " " << b1.upper(4) << " " << b1.size(4) << "\n";
    cout << "\n";
  }

  {
    table<float > b1( nt2::of_size(3,4) );

    using std::cout;

    cout << "2 : " << b1.nDims() << "\n";
    cout << b1.empty() << "\n";
    cout << b1.size() << " " << b1.size(0) << "\n";
    cout << b1.lower(1) << " " << b1.upper(1) << " " << b1.size(1) << "\n";
    cout << b1.lower(2) << " " << b1.upper(2) << " " << b1.size(2) << "\n";
    cout << b1.lower(3) << " " << b1.upper(3) << " " << b1.size(3) << "\n";
    cout << b1.lower(4) << " " << b1.upper(4) << " " << b1.size(4) << "\n";
    cout << "\n";
  }

  {
    table<float, nt2::of_size_<3,1,4> > b1;

    using std::cout;

    cout << "3 : " << b1.nDims() << "\n";
    cout << b1.empty() << "\n";
    cout << b1.size() << " " << b1.size(0) << "\n";
    cout << b1.lower(1) << " " << b1.upper(1) << " " << b1.size(1) << "\n";
    cout << b1.lower(2) << " " << b1.upper(2) << " " << b1.size(2) << "\n";
    cout << b1.lower(3) << " " << b1.upper(3) << " " << b1.size(3) << "\n";
    cout << b1.lower(4) << " " << b1.upper(4) << " " << b1.size(4) << "\n";
    cout << "\n";
  }
}
