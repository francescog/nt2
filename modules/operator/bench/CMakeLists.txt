################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

################################################################################
# Add global unit driver rules
################################################################################
ADD_CUSTOM_TARGET(operator.scalar.bench)
ADD_CUSTOM_TARGET(operator.simd.bench)
ADD_DEPENDENCIES(operator.bench operator.scalar.bench operator.simd.bench)

################################################################################
# Add all bench directories for sdk/
################################################################################
nt2_module_use_modules(unit)
ADD_SUBDIRECTORY(scalar)
