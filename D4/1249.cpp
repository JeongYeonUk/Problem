#pragma warning (disable:4996)
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

using Point = pair<int, int>;

int map[100][100];
int d[100][100];
bool check[100][100];
int N;

const int dx[] = { 1,0, -1, 0 };
const int dy[] = { 0,1, 0, -1 };

void init(int index, string str)
{
	for (int i = 0; i < (int)str.length(); ++i)
	{
		map[index][i] = (str[i] - '0');
	}
}

void bfs(int y, int x)
{
	check[y][x] = true;
	queue<Point> q;
	q.push({ y,x });
	while (!q.empty())
	{
		int nowX = q.front().second;
		int nowY = q.front().first;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];
			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
			{
				if (!check[nextY][nextX] || d[nextY][nextX] > d[nowY][nowX] + map[nextY][nextX])
				{
					d[nextY][nextX] = d[nowY][nowX] + map[nextY][nextX];
					q.push({ nextY, nextX });
					check[nextY][nextX] = true;
				}
			}
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
		memset(check, false, sizeof(check));
		memset(d, 0, sizeof(d));
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			string str; cin >> str;
			init(i, str);
		}
		bfs(0, 0);
		cout << '#' << cases << ' ' << d[N - 1][N - 1] << '\n';
	}

	return 0;
}