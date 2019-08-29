#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int dp[2][100001];
int walk[101][2];
int cycle[101][2];
int N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		cin >> walk[i][0] >> walk[i][1] >> cycle[i][0] >> cycle[i][1];
	}
	dp[1][walk[1][0]] = walk[1][1];
	dp[1][cycle[1][0]] = max(dp[1][cycle[1][0]], cycle[1][1]);

	int cur = 0; int prev = 0;
	for (int i = 2; i <= N; ++i)
	{
		cur = i & 1; prev = (i - 1) & 1;
		memset(dp[cur], 0, sizeof(dp[cur]));
		for (int j = walk[i][0]; j <= K; ++j)
		{
			if (dp[prev][j - walk[i][0]])
				dp[cur][j] = max(dp[cur][j], dp[prev][j - walk[i][0]] + walk[i][1]);
		}
		for (int j = cycle[i][0]; j <= K; ++j)
		{
			if (dp[prev][j - cycle[i][0]])
				dp[cur][j] = max(dp[cur][j], dp[prev][j - cycle[i][0]] + cycle[i][1]);
		}
	}
	cur = N & 1;
	int ans = 0;
	for (int i = 1; i <= K; ++i)
	{
		ans = max(ans, dp[cur][i]);
	}

	cout << ans << '\n';

	return 0;
}