#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxN = 16 + 1;

double p[maxN][maxN];
double dp[maxN][1 << maxN];
int n;

double solve(int y, int visit)
{
	double& ret = dp[y][visit];
	if (ret > 0) return ret;

	if (y >= n) return 1;
	ret = 0;
	for (int i = 0; i < n; ++i) {
		if (visit & (1 << i)) continue;
		if (p[y][i] == 0) continue;
		ret = max(ret, solve(y + 1, (visit | 1 << i)) * p[y][i]);
	}
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T; scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));

		double input;
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				scanf("%lf", &input);
				p[y][x] = input / 100;
			}
		}

		printf("#%d %.6lf\n", t, solve(0, 0) * 100);
	}

	return 0;
}
