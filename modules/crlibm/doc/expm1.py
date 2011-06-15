[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '1',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'T',
            },
         'simd_types' : [],
         'special' : ['crlibm'],
         'type_defs' : [],
         'types' : ['double','float'],
         'tpl' : '<nt2::rn>'   
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 02/03/2011',
             'included' : ['#include <nt2/include/functions/expm1.hpp>'],
             'notes' : [],
             'stamp' : 'modified by jt the 02/03/2011',
            },
         'ranges' : {
             'default' : [['T(-700)', 'T(700)']],
             'float'   : [['T(-85)', 'T(85)']],   
            },
         'specific_values' : {
            },
         'verif_test' : {
             'property_call' : {
                 'default' : ['nt2::crlibm::expm1<rn>(a0)'],
                },
             'property_value' : {
                 'default' : ['nt2::expm1(a0)'],
                },
             'simd' : {
                },
             'ulp_thresh' : {
                 'default' : ['1'],
                },
            },
        },
    },
]
