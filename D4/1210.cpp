#pragma warning (disable : 4996)
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int map[100][100];
int check[100][100];
const int dx[] = { 1,-1,0 };
const int dy[] = { 0,0,-1 };
bool flag;
int solve(int y, int x)
{
	check[y][x] = 1;
	while (true)
	{
		if (y == 0) break;
		for (int i = 0; i < 3; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < 100 && 0 <= nx && nx < 100)
			{
				if (map[ny][nx] == 1 && !check[ny][nx])
				{
					check[ny][nx] = 1;
					x = nx; y = ny;
					break;
				}
			}
		}
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	for (int cases = 1; cases <= 10; ++cases)
	{
		int T; cin >> T;
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		flag = false;
		int start;
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 100; ++j)
			{
				cin >> map[i][j];
				if (map[i][j] == 2)
					start = j;
			}
		}
		int ans = solve(99, start);
		cout << '#' << T << ' ' << ans << '\n';
	}

	return 0;
}