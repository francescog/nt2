#include <vector>
#include <iostream>
#include <nt2/sdk/details/decltype.hpp>

template<class T>
void test(T)
{
  NT2_DECLTYPE( 1.f / int(), type);
  
  type x = 1.f;
}

int main()
{
  test(0);
}
