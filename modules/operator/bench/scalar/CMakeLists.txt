################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

SET( SOURCES
    complement.cpp
    unary_plus.cpp
    unary_minus.cpp
    not.cpp
    plus.cpp
    minus.cpp
    multiplies.cpp
    divides.cpp
   )

################################################################################
# For each filename
################################################################################
FOREACH( EXAMPLE ${SOURCES})
  STRING(REGEX REPLACE ".cpp" "" EXAMPLE ${EXAMPLE})
  nt2_module_add_bench(operator.scalar.${EXAMPLE}.bench ${EXAMPLE}.cpp)
ENDFOREACH()
