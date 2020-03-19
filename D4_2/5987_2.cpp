#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'
#define rint register int

typedef long long ll;

const int INF = 987654321;

int needs[16];
ll dp[1 << 16];
int N, M, x, y;

ll dfs(int visit)
{
	if (visit == (1 << N) - 1) return 1;
	if (dp[visit] > 0) return dp[visit];
	for (rint i = 0; i < N; ++i)
	{
		if (!(visit & (1 << i)))
			if ((visit & needs[i]) == needs[i])
				dp[visit] += dfs((visit | 1 << i));
	}
	return dp[visit];
}

int main() {
	freopen("input.txt", "r", stdin);

	int t; scanf("%d", &t);
	for (rint cases = 1; cases <= t; ++cases)
	{
		memset(needs, 0, sizeof(needs));
		memset(dp, 0, sizeof(dp));
		scanf("%d %d", &N, &M);
		for (rint m = 0; m < M; ++m)
		{
			scanf("%d %d", &x, &y);
			--x, --y;
			needs[x] |= (1 << y);
		}
		printf("#%d %lld\n", cases, dfs(0));
	}

	return 0;
}