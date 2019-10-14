#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

struct INFO
{
	int y, x;
};
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int map[50][50];
int visited[50][50];
INFO tmp[2500];
int tmp_idx;
int n, l, r;
int ret;
int people, num;

void dfs(int sy, int sx)
{
	for (int dir = 0; dir < 4; ++dir)
	{
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];
		if (ny >= n || nx >= n || ny < 0 || nx < 0)
			continue;
		int delta = abs(map[sy][sx] - map[ny][nx]);
		if (!visited[ny][nx] && l <= delta && delta <= r)
		{
			visited[ny][nx] = true;
			tmp[tmp_idx++] = { ny,nx };
			people += map[ny][nx];
			num++;
			dfs(ny, nx);
		}
	}
}


int main()
{
	scanf("%d %d %d", &n, &l, &r);
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			scanf("%d", &map[y][x]);
		}
	}

	
	ret = 0;
	while (true)
	{
		bool is_update = false;
		memset(visited, 0, sizeof(visited));
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				if (visited[y][x])
					continue;
				// marking
				visited[y][x] = true;
				people = map[y][x];
				num = 1;
				tmp_idx = 0;
				tmp[tmp_idx++] = { y,x };
				dfs(y, x);
				if (num >= 2)
				{
					is_update = true;
					for (int i = 0; i < tmp_idx; ++i)
					{
						map[tmp[i].y][tmp[i].x] = people / num;
					}
				}
			}
		}
		if (is_update)
			ret++;
		else
			break;
	}
	printf("%d\n", ret);
	return 0;
}
