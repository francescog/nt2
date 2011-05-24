##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

################################################################################
# Add global unit driver rules
################################################################################
ADD_CUSTOM_TARGET(core.extent.unit)
ADD_CUSTOM_TARGET(core.table.unit)
ADD_DEPENDENCIES(core.unit core.extent.unit core.table.unit)

##****************************************************************************
##*     Toolbox crlibm unit tests
##****************************************************************************
nt2_module_use_modules(unit core sdk arithmetic)
ADD_SUBDIRECTORY(extent)
ADD_SUBDIRECTORY(table)