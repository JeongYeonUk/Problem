#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

int map[101][101];
int curve[1025];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		map[y][x] = 1;

		int curve_idx = 0;
		curve[curve_idx++] = d;
		for (int j = 0; j < g; ++j)
		{
			for (int k = curve_idx - 1; k >= 0; --k)
			{
				curve[curve_idx++] = (curve[k] + 1) % 4;
			}
		}

		for (int j = 0; j < curve_idx; ++j)
		{
			x += dx[curve[j]];
			y += dy[curve[j]];
			if (x < 0 || y < 0 || x > 101 || y > 101)
				continue;
			map[y][x] = 1;
		}
	}

	int ret = 0;
	for (int y = 0; y < 100; ++y)
	{
		for (int x = 0; x < 100; ++x)
		{
			if (map[y][x] && map[y][x + 1] && map[y + 1][x] && map[y + 1][x + 1])
				++ret;
		}
	}
	printf("%d\n", ret);
	return 0;
}
