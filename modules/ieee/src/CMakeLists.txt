################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

include(NT2Module)
nt2_module_source_setup(ieee)
nt2_module_configure_toolbox(ieee 1)

################################################################################
# Find out which C99/TR1 math functions are available
################################################################################

include(CheckFunctionExists)

if(UNIX)
  set(CMAKE_REQUIRED_LIBRARIES m)
endif()

check_function_exists(ilogb NT2_TOOLBOX_IEEE_HAS_ILOGB)
check_function_exists(ilogbf NT2_TOOLBOX_IEEE_HAS_ILOGBF)

check_function_exists(copysign NT2_TOOLBOX_IEEE_HAS_COPYSIGN)
check_function_exists(copysignf NT2_TOOLBOX_IEEE_HAS_COPYSIGNF)
check_function_exists(_copysign NT2_TOOLBOX_IEEE_HAS__COPYSIGN)
check_function_exists(_copysignf NT2_TOOLBOX_IEEE_HAS__COPYSIGNF)

check_function_exists(nextafter NT2_TOOLBOX_IEEE_HAS_NEXTAFTER)
check_function_exists(nextafterf NT2_TOOLBOX_IEEE_HAS_NEXTAFTERF)
check_function_exists(_nextafter NT2_TOOLBOX_IEEE_HAS__NEXTAFTER)
check_function_exists(_nextafterf NT2_TOOLBOX_IEEE_HAS__NEXTAFTERF)

################################################################################
# Generate math.hpp
################################################################################
nt2_module_configure_file(math.hpp.cmake
                          nt2/toolbox/ieee/details/math.hpp
                         )
