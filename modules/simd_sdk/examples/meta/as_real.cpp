#include <boost/mpl/assert.hpp>
#include <nt2/sdk/config/types.hpp>
#include <nt2/sdk/simd/pack.hpp>
#include <nt2/sdk/meta/as_real.hpp>
#include <boost/type_traits/is_same.hpp>

using nt2::int32_t;
using nt2::uint32_t;
using nt2::uint64_t;
using boost::is_same;
using nt2::simd::pack;

int main()
{
  BOOST_MPL_ASSERT(( is_same<float,       nt2::meta::as_real<int32_t>::type>         ));
  BOOST_MPL_ASSERT(( is_same<float,       nt2::meta::as_real<uint32_t>::type>        ));
  BOOST_MPL_ASSERT(( is_same<double,      nt2::meta::as_real<uint64_t>::type>        ));
  BOOST_MPL_ASSERT(( is_same<pack<float>, nt2::meta::as_real<pack<int32_t> >::type> ));
}
