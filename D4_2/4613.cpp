#pragma warning (disable:4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int n, m;
char flag[50][51];
int cache[50][50][50];

int check(int sy, int ey, char pivot)
{
	int cnt = 0;
	for (int y = sy; y < ey; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			if (flag[y][x] != pivot)
				cnt++;
		}
	}
	return cnt;
}

int solve(int white, int blue, int red)
{
	if (white > n - 2 || blue > n - 2 || red > n - 2)
		return INF;
	if (white < 1 || blue < 1 || red < 1)
		return INF;
	int& ret = cache[white][blue][red];
	if (ret != -1)
		return ret;
	ret = 0;
	ret += check(0, white, 'W');
	ret += check(white, white + blue, 'B');
	ret += check(white + blue, white + blue + red, 'R');

	ret = min(ret, solve(white, blue + 1, red - 1));
	ret = min(ret, solve(white + 1, blue, red - 1));
	ret = min(ret, solve(white - 1, blue + 1, red));
	ret = min(ret, solve(white - 1, blue, red + 1));
	ret = min(ret, solve(white + 1, blue - 1, red));
	ret = min(ret, solve(white, blue - 1, red + 1));

	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T; scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases)
	{
		memset(cache, -1, sizeof(cache));
		scanf("%d %d", &n, &m);
		for (int y = 0; y < n; ++y)
		{
			scanf("%s", &flag[y]);
		}

		int ret = min({ solve(n - 2,1,1), solve(1,n - 2,1),solve(1, 1, n - 2) });
		printf("#%d %d\n",cases, ret);
	}

	return 0;
}
