#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };
struct CLEAN
{
	int y, x;
};

int map[50][50];
bool visited[50][50];
int r, c, t;
int ret;
CLEAN upClean, downClean;

void map_copy(int desc[][50], int src[][50])
{
	for (int y = 0; y < r; ++y)
	{
		for (int x = 0; x < c; ++x)
		{
			desc[y][x] = src[y][x];
		}
	}
}

void up()
{
	int move_map[50][50] = { 0, };
	map_copy(move_map, map);

	// right
	for (int x = upClean.x + 1; x < c - 1; ++x)
	{
		if (x == upClean.x + 1)
		{
			move_map[upClean.y][x] = 0;
		}
		move_map[upClean.y][x + 1] = map[upClean.y][x];
	}
	// up
	for (int y = upClean.y; y > 0; --y)
	{
		move_map[y - 1][c - 1] = map[y][c - 1];
	}
	// left
	for (int x = c - 1; x > 0; --x)
	{
		move_map[0][x - 1] = map[0][x];
	}
	// down
	for (int y = 0; y < upClean.y; ++y)
	{
		if (y + 1 == upClean.y)
			continue;
		move_map[y + 1][0] = map[y][0];
	}
	map_copy(map, move_map);
}

void down()
{
	int move_map[50][50] = { 0, };
	map_copy(move_map, map);

	// right
	for (int x = downClean.x + 1; x < c - 1; ++x)
	{
		if (x == downClean.x + 1)
		{
			move_map[downClean.y][x] = 0;
		}
		move_map[downClean.y][x + 1] = map[downClean.y][x];
	}
	// down
	for (int y = downClean.y; y < r - 1; ++y)
	{
		move_map[y + 1][c - 1] = map[y][c - 1];
	}
	// left
	for (int x = c - 1; x > 0; --x)
	{
		move_map[r - 1][x - 1] = map[r - 1][x];
	}
	// up
	for (int y = r - 1; y > downClean.y; --y)
	{
		if (y - 1 == downClean.y)
			break;
		move_map[y - 1][0] = map[y][0];
	}
	map_copy(map, move_map);
}

void update()
{
	for (int y = 0; y < r; ++y)
	{
		for (int x = 0; x < c; ++x)
		{
			if (map[y][x] != -1 && map[y][x] != 0)
				visited[y][x] = true;
		}
	}
}

int main()
{
	scanf("%d %d %d", &r, &c, &t);
	for (int y = 0; y < r; ++y)
	{
		for (int x = 0; x < c; ++x)
		{
			scanf("%d", &map[y][x]);
			if (map[y][x] == -1)
			{
				if (upClean.y == 0)
				{
					upClean.y = y;
					upClean.x = x;
				}
				else
				{
					downClean.y = y;
					downClean.x = x;
				}
			}
		}
	}

	while (t--)
	{
		update();
		int backup[50][50] = { 0, };
		for (int y = 0; y < r; ++y)
		{
			for (int x = 0; x < c; ++x)
			{
				if (visited[y][x])
				{
					int temp = map[y][x];
					for (int dir = 0; dir < 4; ++dir)
					{
						int ny = y + dy[dir];
						int nx = x + dx[dir];
						if (ny < 0 || nx < 0 || ny >= r || nx >= c)
							continue;
						if (map[ny][nx] == -1)
							continue;
						backup[ny][nx] += temp / 5;
						map[y][x] -= temp / 5;
					}
				}
			}
		}
		for (int y = 0; y < r; ++y)
		{
			for (int x = 0; x < c; ++x)
			{
				map[y][x] += backup[y][x];
			}
		}

		up();
		down();
	}

	for (int y = 0; y < r; ++y)
	{
		for (int x = 0; x < c; ++x)
		{
			if (map[y][x] == -1)
				continue;
			ret += map[y][x];
		}
	}
	printf("%d\n", ret);
	return 0;
}
