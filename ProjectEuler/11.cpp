#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

const int dx[] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[] = { 0,1,1,1,0,-1,-1,-1 };

int map[20][21];

int bfs(int sy, int sx, int dir)
{
	int ret = map[sy][sx];
	for (int i = 0; i < 3; ++i)
	{
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];
		if (ny < 0 || nx < 0 || ny >= 20 || nx >= 20)
			continue;
		ret *= map[ny][nx];
		sy = ny, sx = nx;
	}
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);

	for (int y = 0; y < 20; ++y)
	{
		for (int x = 0; x < 20; ++x)
		{
			char c[3]; scanf("%s", c);
			map[y][x] = ((c[0] - '0') * 10)
				+ (c[1] - '0');
		}
	}
	int ret = 0;
	for (int y = 0; y < 20; ++y)
	{
		for (int x = 0; x < 20; ++x)
		{
			for (int dir = 0; dir < 8; ++dir)
			{
				int candi = bfs(y, x, dir);
				if (candi > ret)
					ret = candi;
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}