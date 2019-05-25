#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using Point = pair<int, int>;

int map[8][8];
int check[8][8];
int N, K;
bool chk;
int ans;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y, int now, int depth)
{
	if (check[y][x]) return;
	check[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
		{
			if (now > map[nextY][nextX])
				dfs(nextX, nextY, map[nextY][nextX], depth + 1);
			if (!chk)
			{
				for (int i = 1; i <= K; ++i)
				{
					if (now > map[nextY][nextX] - i)
					{
						chk = true;
						dfs(nextX, nextY, map[nextY][nextX] - i, depth + 1);
						chk = false;
					}
				}
			}
		}
	}
	check[y][x] = 0;
	if (ans < depth)
		ans = depth;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		cin >> N >> K;
		ans = 0;
		int max = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> map[i][j];
				if (max < map[i][j])
					max = map[i][j];
			}
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (max == map[i][j])
				{
					dfs(j, i, map[i][j], 1);
				}
			}
		}
		cout << '#' << cases << ' ' << ans << '\n';
	}

	return 0;
}