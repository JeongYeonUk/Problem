#include <iostream>
#include <cstring>
using namespace std;

int arr[101][101];
int dp[101][101];
int N;
inline int MAX(int a, int b)
{
	return a > b ? a : b;
}

int solve(int y, int x)
{
	if (y == N - 1)
		return arr[y][x];
	int& ret = dp[y][x];
	if (ret != -1)
		return ret;
	return ret = MAX(solve(y + 1, x), solve(y + 1, x + 1))
		+ arr[y][x];
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
			for (int j = 0; j <= i; ++j)
			{
				cin >> arr[i][j];
			}
		}

		cout << solve(0,0) << '\n';
	}

	return 0;
}