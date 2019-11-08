#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;

ll tri_num(ll nth)
{
	return nth * (nth + 1) / 2;
}

ll dcnt(ll num)
{
	ll cnt = 1;
	ll p = 2;
	while (num >= p * p)
	{
		if (num % p == 0)
		{
			ll pcnt = 0;
			while (num % p == 0)
			{
				num /= p;
				pcnt++;
			}
			cnt *= (pcnt + 1);
		}
		else
			p++;
	}
	if (num != 1)
		cnt *= 2;
	return cnt;
}

int main()
{
	for (ll i = 1; ; ++i)
	{
		ll tn = tri_num(i);
		if (dcnt(tn) >= 500)
		{
			printf("%lld\n", tn);
			break;
		}
	}
	return 0;
}