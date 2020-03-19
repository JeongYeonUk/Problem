#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

/*
3
3 2
1 2
1 3
5 5
1 2
2 5
1 3
3 4
4 5
16 1
5 9

#1 2
#2 3
#3 10461394944000
*/

#define endl '\n'
#define rint register int
typedef long long ll;

const int INF = 987654321;
bool adj[17][17];
int N, M, x, y, indeg[17];
ll dp[1 << 16];

ll solve(int now, int visit)
{
	if (visit == (1 << N) - 1) return 1;
	if (dp[visit] != -1) return dp[visit];
	dp[visit]++;
	for (rint i = 1; i < 17; ++i)
	{
		if (adj[now][i])
			indeg[i]--;
	}
	for (rint i = 1; i <= N; ++i)
	{
		if (!indeg[i])
			if (!(visit & (1 << (i - 1))))
				dp[visit] += solve(i, visit | (1 << ( i - 1)));
	}
	for (rint i = 1; i < 17; ++i)
	{
		if (adj[now][i])
			indeg[i]++;
	}
	return dp[visit];
}

int main() {
	freopen("input.txt", "r", stdin);

	int t; scanf("%d", &t);
	for (rint cases = 1; cases <= t; ++cases)
	{
		memset(adj, false, sizeof(adj));
		memset(indeg, 0, sizeof(indeg));
		memset(dp, -1, sizeof(dp));
		scanf("%d %d", &N, &M);
		for (rint m = 0; m < M; ++m)
		{
			scanf("%d %d", &x, &y);
			adj[x][y] = true;
			indeg[y]++;
		}
		printf("#%d %lld\n", cases, solve(0, 0));
	}

	return 0;
}