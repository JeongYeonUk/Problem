#include <iostream>
#include <cstring>
using namespace std;

int board[100][100];
int dp[100][100];
int N;

int solve(int y, int x)
{
	if (y >= N || x >= N)
		return 0;
	if (y == N - 1 && x == N - 1)
		return 1;
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	int jumpSize = board[y][x];
	return ret = (solve(y, x + jumpSize) || solve(y + jumpSize, x));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		memset(dp, -1, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> board[i][j];
			}
		}
		int answer = solve(0,0);
		cout << (answer ? "YES" : "NO") << '\n';
	}

	return 0;
}