    template<class This, class A0 > struct result<This(A0)> { typedef typename meta::dispatch_call<Tag(A0),EvalContext>::type callee; typedef typename meta::result_of<callee(A0)>::type type; }; template<class A0> inline typename meta::enable_call< Tag(A0) , EvalContext>::type operator()(A0 && a0) const { typename meta::dispatch_call<Tag(A0) ,EvalContext >::type callee; return callee( std::forward<A0>(a0) ); } template<class This, class A0 , class A1 > struct result<This(A0 , A1)> { typedef typename meta::dispatch_call<Tag(A0 , A1),EvalContext>::type callee; typedef typename meta::result_of<callee(A0 , A1)>::type type; }; template<class A0 , class A1> inline typename meta::enable_call< Tag(A0 , A1) , EvalContext>::type operator()(A0 && a0 , A1 && a1) const { typename meta::dispatch_call<Tag(A0 , A1) ,EvalContext >::type callee; return callee( std::forward<A0>(a0) , std::forward<A1>(a1) ); } template<class This, class A0 , class A1 , class A2 > struct result<This(A0 , A1 , A2)> { typedef typename meta::dispatch_call<Tag(A0 , A1 , A2),EvalContext>::type callee; typedef typename meta::result_of<callee(A0 , A1 , A2)>::type type; }; template<class A0 , class A1 , class A2> inline typename meta::enable_call< Tag(A0 , A1 , A2) , EvalContext>::type operator()(A0 && a0 , A1 && a1 , A2 && a2) const { typename meta::dispatch_call<Tag(A0 , A1 , A2) ,EvalContext >::type callee; return callee( std::forward<A0>(a0) , std::forward<A1>(a1) , std::forward<A2>(a2) ); } template<class This, class A0 , class A1 , class A2 , class A3 > struct result<This(A0 , A1 , A2 , A3)> { typedef typename meta::dispatch_call<Tag(A0 , A1 , A2 , A3),EvalContext>::type callee; typedef typename meta::result_of<callee(A0 , A1 , A2 , A3)>::type type; }; template<class A0 , class A1 , class A2 , class A3> inline typename meta::enable_call< Tag(A0 , A1 , A2 , A3) , EvalContext>::type operator()(A0 && a0 , A1 && a1 , A2 && a2 , A3 && a3) const { typename meta::dispatch_call<Tag(A0 , A1 , A2 , A3) ,EvalContext >::type callee; return callee( std::forward<A0>(a0) , std::forward<A1>(a1) , std::forward<A2>(a2) , std::forward<A3>(a3) ); } template<class This, class A0 , class A1 , class A2 , class A3 , class A4 > struct result<This(A0 , A1 , A2 , A3 , A4)> { typedef typename meta::dispatch_call<Tag(A0 , A1 , A2 , A3 , A4),EvalContext>::type callee; typedef typename meta::result_of<callee(A0 , A1 , A2 , A3 , A4)>::type type; }; template<class A0 , class A1 , class A2 , class A3 , class A4> inline typename meta::enable_call< Tag(A0 , A1 , A2 , A3 , A4) , EvalContext>::type operator()(A0 && a0 , A1 && a1 , A2 && a2 , A3 && a3 , A4 && a4) const { typename meta::dispatch_call<Tag(A0 , A1 , A2 , A3 , A4) ,EvalContext >::type callee; return callee( std::forward<A0>(a0) , std::forward<A1>(a1) , std::forward<A2>(a2) , std::forward<A3>(a3) , std::forward<A4>(a4) ); }
