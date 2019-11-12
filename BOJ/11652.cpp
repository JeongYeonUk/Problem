#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
int main()
{
	int n; scanf("%d", &n);
	map<ll, int> m;
	for (int i = 0; i < n; ++i)
	{
		ll x; scanf("%lld", &x);
		m[x]++;
	}
	int maxi = 0;
	ll ret = 0;
	for (auto a : m)
	{
		if (a.second > maxi)
		{
			maxi = a.second;
			ret = a.first;
		}
		else if (a.second == maxi && a.first < ret)
		{
			ret = a.first;
		}
	}
	printf("%lld\n", ret);
	return 0;
}
