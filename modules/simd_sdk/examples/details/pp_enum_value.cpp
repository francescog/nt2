#include <iostream>
#include <nt2/sdk/details/preprocessor.hpp>

int main()
{
  std::cout << NT2_PP_DEBUG( NT2_PP_ENUM_VALUE(5,6) ) << std::endl;
}
