################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

include(NT2Module)
nt2_module_source_setup(exponential)
nt2_module_configure_toolbox(exponential 1)

nt2_module_configure_include(nt2/toolbox/exponential/function/scalar/impl constants.hpp
                             -o nt2/toolbox/exponential/include
                            )

################################################################################
# Find out which C99/TR1 math functions are available
################################################################################

include(CheckFunctionExists)

if(UNIX)
  set(CMAKE_REQUIRED_LIBRARIES m)
endif()

check_function_exists(cbrt NT2_TOOLBOX_EXPONENTIAL_HAS_CBRT)
check_function_exists(cbrtf NT2_TOOLBOX_EXPONENTIAL_HAS_CBRTF)

################################################################################
# Generate math.hpp
################################################################################
nt2_module_configure_file(math.hpp.cmake
                          nt2/toolbox/exponential/details/math.hpp
                         )
