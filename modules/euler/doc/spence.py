[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '1',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'typename boost::result_of<nt2::meta::floating(T)>::type',
            },
         'simd_types' : ['real_'],
         'type_defs' : [],
         'types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 22/02/2011',
             'included' : [],
             'notes' : [],
             'stamp' : 'modified by jt the 22/02/2011',
            },
         'ranges' : {
             'default' : [['nt2::Valmin<T>()', 'nt2::Valmax<T>()']],
             'real_' : [['T(-100)', 'T(100)']],
             'signed_int_' : [],
             'unsigned_int_' : [],
            },
         'specific_values' : {
             'default' : {
                 'nt2::One<T>()' : {'result' : 'nt2::One<r_t>()','ulp_thresh' : '0',},
                 'nt2::Zero<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0',},
                },
             'real_' : {
                 'nt2::Inf<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Minf<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Mone<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Nan<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::One<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Zero<T>()' : {'result' : '1.6449340668482264061','ulp_thresh' : '0.5',},
                },
             'signed_int_' : {
                 'nt2::Mone<T>()' : {'result' : 'nt2::Mone<r_t>()','ulp_thresh' : '0',},
                 'nt2::One<T>()' : {'result' : 'nt2::One<r_t>()','ulp_thresh' : '0',},
                 'nt2::Zero<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0',},
                },
            },
         'verif_test' : {
             'nb_rand' : {
                 'default' : 'NT2_NB_RANDOM_TEST',
                },
             'property_call' : {
                 'default' : ['nt2::spence(a0)'],
                },
             'property_value' : {
                 'default' : ['nt2::spence(a0)'],
                },
             'ulp_thresh' : {
                 'default' : ['2'],
                },
            },
        },
    },
]
