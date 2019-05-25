#pragma warning (disable:4996)
#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int map[4][4];
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
set<int> ans;

void solve(int y, int x, int value, int count)
{
	if (count == 7)
	{
		ans.insert(value);
		return;
	}
	int num = value * 10 + map[y][x];
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < 4 && 0 <= ny && ny < 4)
		{
			solve(ny, nx, num, count + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		ans.clear();
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				solve(i, j, 0, 0);
			}
		}
		cout << '#' << cases << ' ' << (int)ans.size() << '\n';
	}

	return 0;
}