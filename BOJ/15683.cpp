#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

struct CCTV
{
	int y, x, type;
};

int n, m, ret;
int map[8][8];
int cctv_size;
CCTV cctv[8];

const int rot_type[] = { 4,2,4,4,1 };

void map_copy(int desc[8][8], int src[8][8])
{
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			desc[y][x] = src[y][x];
		}
	}
}

void update(int dir, CCTV cctv)
{
	dir %= 4;

	if (dir == 0)
	{
		for (int x = cctv.x; x < m; ++x)
		{
			if (map[cctv.y][x] == 6)
				break;
			map[cctv.y][x] = -1;
		}
	}
	else if (dir == 1)
	{
		for (int y = cctv.y; y >= 0; --y)
		{
			if (map[y][cctv.x] == 6)
				break;
			map[y][cctv.x] = -1;
		}
	}
	else if (dir == 2)
	{
		for (int x = cctv.x; x >= 0; --x)
		{
			if (map[cctv.y][x] == 6)
				break;
			map[cctv.y][x] = -1;
		}
	}
	else if (dir == 3)
	{
		for (int y = cctv.y; y < n; ++y)
		{
			if (map[y][cctv.x] == 6)
				break;
			map[y][cctv.x] = -1;
		}
	}
}

void dfs(int cctv_index)
{
	if (cctv_index == cctv_size)
	{
		int candi = 0;
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < m; ++x)
			{
				if (map[y][x] == 0)
					++candi;
			}
		}
		if (ret > candi)
			ret = candi;
		return;
	}

	int backup[8][8];
	int type = cctv[cctv_index].type;
	for (int dir = 0; dir < rot_type[type]; ++dir)
	{
		map_copy(backup, map);
		if (type == 0)
		{
			update(dir, cctv[cctv_index]);
		}
		else if (type == 1)
		{
			update(dir, cctv[cctv_index]);
			update(dir + 2, cctv[cctv_index]);
		}
		else if (type == 2)
		{
			update(dir, cctv[cctv_index]);
			update(dir + 1, cctv[cctv_index]); 
		}
		else if (type == 3)
		{
			update(dir, cctv[cctv_index]);
			update(dir + 1, cctv[cctv_index]);
			update(dir + 2, cctv[cctv_index]);
		}
		else if (type == 4)
		{
			update(dir, cctv[cctv_index]);
			update(dir + 1, cctv[cctv_index]);
			update(dir + 2, cctv[cctv_index]);
			update(dir + 3, cctv[cctv_index]);
		}
		dfs(cctv_index + 1);
		map_copy(map, backup);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int y = 0; y < n; ++y) 
	{
		for (int x = 0; x < m; ++x)
		{
			scanf("%d", &map[y][x]);

			if (map[y][x] != 0 && map[y][x] != 6)
			{
				cctv[cctv_size].y = y;
				cctv[cctv_size].x = x;
				cctv[cctv_size].type = map[y][x] - 1;
				++cctv_size;
			}
		}
	}

	ret = INF;
	dfs(0);
	printf("%d\n", ret);

	return 0;
}
