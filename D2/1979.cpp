#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 15;
int map[MAX][MAX];
int N, K;
int checkRow(int y, int x)
{
	int count = 0;
	int ans = 0;
	for (int i = x; i < N; ++i)
	{
		if (map[y][i])
			count++;
		else
		{
			if (count == K)
			{
				ans += 1;
				count = 0;
			}
			else
				count = 0;
		}

	}
	if (count == K)
		ans++;
	if (count == N)
		return 0;
	return ans;
}
int checkCol(int y, int x)
{
	int count = 0;
	int ans = 0;
	for (int i = y; i < N; ++i)
	{
		if (map[i][x])
			count++;
		else
		{
			if (count == K)
			{
				ans += 1;
				count = 0;
			}
			else
				count = 0;
		}
	}
	if (count == K)
		ans++;
	if (count == N)
		return 0;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		cin >> N >> K;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> map[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < N; ++i)
		{
			ans += checkRow(i, 0);
		}
		for (int i = 0; i < N; ++i)
		{
			ans += checkCol(0, i);
		}
		cout << '#' << cases << ' ' << ans << '\n';
	}

	return 0;
}