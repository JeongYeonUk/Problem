#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
int n, l;
int map[100][100];
bool visited[100][100];
int ret;

bool solve(int sy, int sx, int dir)
{
	int val = map[sy][sx];
	switch (dir)
	{
	case 0:
		for (int x = sx; x < sx + l; ++x)
		{
			if (x > n)
				return false;
			if (val != map[sy][x])
				return false;
			if (visited[sy][x])
				return false;
			visited[sy][x] = true;
		}
		break;
	case 1:
		for (int y = sy; y < sy + l; ++y)
		{
			if (y > n)
				return false;
			if (val != map[y][sx])
				return false;
			if (visited[y][sx])
				return false;
			visited[y][sx] = true;
		}
		break;
	case 2:
		for (int x = sx; x > sx - l; --x)
		{
			if (x < 0)
				return false;
			if (val != map[sy][x])
				return false;
			if (visited[sy][x])
				return false;
			visited[sy][x] = true;
		}
		break;
	case 3:
		for (int y = sy; y > sy - l; --y)
		{
			if (y < 0)
				return false;
			if (val != map[y][sx])
				return false;
			if (visited[y][sx])
				return false;
			visited[y][sx] = true;
		}
		break;
	default:
		break;
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &l);
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			scanf("%d", &map[y][x]);
		}
	}

	//right;
	bool dupli;
	bool ok;
	for (int y = 0; y < n; ++y)
	{
		dupli = true;
		ok = true;
		for (int x = 1; x < n; ++x)
		{
			// pivot = map[y][x]
			if (map[y][x-1] - map[y][x] == 1)
			{
				dupli = false;
				if (!solve(y, x, 0))
				{
					ok = false;
					break;
				}
			}
			// pivot = map[y-1][x]
			else if (map[y][x-1] - map[y][x] == -1)
			{
				dupli = false;
				if (!solve(y, x - 1, 2))
				{
					ok = false;
					break;
				}
			}
			else if (map[y][x-1] - map[y][x] != 0)
			{
				dupli = false;
				ok = false;
				break;
			}
		}
		if ((dupli && ok) || (!dupli && ok))
			ret++;
	}
	memset(visited, false, sizeof(visited));
	//down;
	for (int x = 0; x < n; ++x)
	{
		dupli = true;
		ok = true;
		for (int y = 1; y < n; ++y)
		{
			// pivot = map[y][x]
			if (map[y-1][x] - map[y][x] == 1)
			{
				dupli = false;
				if (!solve(y, x, 1))
				{
					ok = false;
					break;
				}
			}
			// pivot = map[y-1][x]
			else if (map[y-1][x] - map[y][x] == -1)
			{
				dupli = false;
				if (!solve(y - 1, x, 3))
				{
					ok = false;
					break;
				}
			}
			else if (map[y-1][x] - map[y][x] != 0)
			{
				dupli = false;
				ok = false;
				break;
			}
		}
		if ((dupli && ok) || (!dupli && ok))
			ret++;
	}
	printf("%d\n", ret);

	return 0;
}
