
################################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

SET( SOURCES
  sqrt1pm1.cpp
  powi.cpp
  pow.cpp
  nthroot.cpp
  log2.cpp
  log1p.cpp
  log10.cpp
  log.cpp
  expx2.cpp
  expm1.cpp
  exp2.cpp
  exp10.cpp
  exp.cpp
  cbrt.cpp
# List of simd test files for toolbox exponential
   )

##############################################################################
# For each filename
##############################################################################
FOREACH( EXAMPLE ${SOURCES})
  STRING(REGEX REPLACE ".cpp" "" EXAMPLE ${EXAMPLE})
  nt2_module_add_cover(exponential.simd.${EXAMPLE}.cover ${EXAMPLE}.cpp)
ENDFOREACH()

