#pragma warning (disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 987654321;
const int dx[] = { 0,2 };
const int dy[] = { 2,0 };

int map[1010][1010];
int n, m, ret;
int main()
{
	//freopen("input.txt", "r", stdin);

	int T; scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases)
	{
		scanf("%d %d", &n, &m);
		memset(map, 0, sizeof(map));
		ret = n * m;
		for (int y = 2; y <= m + 1; ++y)
		{
			for (int x = 2; x <= n + 1; ++x)
			{
				if (map[y][x])
					continue;
				for (int dir = 0; dir < 2; ++dir)
				{
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if (ny >= 2 && ny <= m + 1 && nx >= 2 && nx <= n + 1 && map[ny][nx] == 0)
					{
						map[ny][nx] = 1;
						ret--;
					}
				}
			}
		}
		printf("#%d %d\n", cases, ret);
	}

	return 0;
}
