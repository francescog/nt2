################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

include(NT2Module)
nt2_module_source_setup(sdk)

################################################################################
# Generate bootstrap.hpp
################################################################################
CONFIGURE_FILE( ${NT2_SDK_ROOT}/src/bootstrap.hpp.cmake
                ${PROJECT_BINARY_DIR}/include/nt2/sdk/config/bootstrap.hpp
              )
              
nt2_module_configure_simd( nt2/sdk/simd/details/impl --no-simd-dir --no-default-baseline
                                                     -Bcommon -Bsse/sse2
                         )

file( GLOB_RECURSE source_files
      ${NT2_SDK_ROOT}/src/*
    )
    
nt2_module_add_library(nt2 ${source_files})