#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int map[31][11];
int n, m, h, ret;

bool check()
{
	for (int i = 1; i <= n; ++i)
	{
		int num = i;
		for (int j = 0; j <= h; ++j)
		{
			if (map[j][num])
				num = num + 1;
			else if (map[j][num - 1])
				num = num - 1;
		}
		if (num != i)
			return false;
	}
	return true;
}

void dfs(int y, int x, int cnt)
{
	if (cnt >= ret) 
		return;
	if (check())
	{
		if (ret > cnt)
			ret = cnt;
		return;
	}
	if (cnt == 3)
		return;
	for (int i = y; i <= h; ++i)
	{
		for (int j = x; j < n; ++j)
		{
			if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i][j + 1] == 0)
			{
				map[i][j] = 1;
				dfs(i, j, cnt + 1);
				map[i][j] = 0;
			}
		}
		x = 1;
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &h);
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}

	ret = 4;
	dfs(1, 1, 0);
	if (ret == 4) ret = -1;
	printf("%d\n", ret);

	return 0;
}
