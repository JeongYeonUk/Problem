#pragma warning (disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 987654321;
int map[20][20];
char input[6];
int n;

void answer()
{
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			printf("%d ", map[y][x]);
		}
		printf("\n");
	}
}

void rotate_clock()
{
	int backup[20][20] = {0,};
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			backup[y][x] = map[n - x - 1][y];
		}
	}
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			map[y][x] = backup[y][x];
		}
	}
}

void rotate_nonclock()
{
	int backup[20][20] = { 0, };
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			backup[y][x] = map[x][n-y-1];
		}
	}
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			map[y][x] = backup[y][x];
		}
	}
}

void up()
{
	int backup[20][20] = { 0, };
	for (int x = 0; x < n; ++x)
	{
		int flag = 0, target = -1;
		for (int y = 0; y < n; ++y)
		{
			if (map[y][x] == 0)
				continue;
			if (flag == 1 && map[y][x] == backup[target][x])
			{
				backup[target][x] *= 2, flag = 0;
			}
			else
			{
				backup[++target][x] = map[y][x], flag = 1;
			}
		}
		for (++target; target < n; ++target)
		{
			backup[target][x] = 0;
		}
	}
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			map[y][x] = backup[y][x];
		}
	}
}

void solve(char ch)
{
	if (ch == 'l')
	{
		for (int i = 0; i < 3; ++i)
			rotate_nonclock();
		up();
		for (int i = 0; i < 3; ++i)
			rotate_clock();
	}
	else if (ch == 'r')
	{
		rotate_nonclock();
		up();
		rotate_clock();
	}
	else if (ch == 'u')
	{
		up();
	}
	else if (ch == 'd')
	{
		for (int i = 0; i < 2; ++i)
			rotate_nonclock();
		up();
		for (int i = 0; i < 2; ++i)
			rotate_clock();
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T; scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases)
	{
		memset(map, 0, sizeof(map));
		memset(input, 0, sizeof(input));
		scanf("%d %s", &n, input);
		//scanf("%s", input);
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				scanf("%d", &map[y][x]);
			}
		}
		solve(input[0]);
		printf("#%d\n", cases);
		answer();
	}

	return 0;
}
