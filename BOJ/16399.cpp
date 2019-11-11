#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 987654321;

pii vec[1002];
ll dp[1002][501];

int main()
{
	int c, e, d, n;
	scanf("%d %d %d", &c, &e, &d);
	scanf("%d", &n);

	vec[0].first = 0; vec[0].second = 10001;

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &vec[i].first);
		vec[i].first += vec[i - 1].first;
	}
	for (int i = 1; i <= n; ++i)
		scanf("%d", &vec[i].second);

	vec[n + 1].first = d;
	vec[n + 1].second = 10001;
	n += 2;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= c; ++j)
			dp[i][j] = 2e18;
	}
	dp[0][c] = 0;

	for (int i = 1; i < n; ++i)
	{
		int kk = e * (vec[i].first - vec[i - 1].first);

		for (int j = 0; j <= c; ++j)
		{
			if (j <= c - kk)
				dp[i][j] = dp[i - 1][j + kk];
			if (j)
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + vec[i].second);
		}
	}

	ll miv = 2e18;
	for (int i = 0; i <= c; ++i)
		miv = min(miv, dp[n - 1][i]);

	if (miv > 1e18)
		return !printf("-1");
	printf("%lld", miv);
	return 0;
}
