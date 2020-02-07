#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

const int dx[] = { 0,1,1,1 };
const int dy[] = { 1,1,0,-1 };

int map[20][20];
int cache[20][20][4];

int ans;
bool flag;
int solve(int x, int y, int dir, int cnt, int block) {

	if (flag == false) {
		return cache[x][y][dir] = 0;
	}
	if (cnt > 5) {
		return cache[x][y][dir] = 0;
	}

	int& ret = cache[x][y][dir];
	if (ret != -1)
		return ret;

	int nx = x + dx[dir];
	int ny = y + dy[dir];
	ret = 0;
	if (nx < 1 || ny < 1 || nx > 19 || ny > 19 || map[nx][ny] != block) {
		if (cnt == 5) {
			ans = block;
			return ret = cnt;
		}
		else {
			flag = false;
			return ret = 0;
		}
	}
	
	return ret = solve(nx, ny, dir, cnt + 1, block);
}

int main()
{
	for (int x = 1; x < 20; ++x) {
		for (int y = 1; y < 20; ++y) {
			scanf("%d", &map[x][y]);
		}
	}

	memset(cache, -1, sizeof(cache));

	for (int x = 1; x < 20; ++x) {
		for (int y = 1; y < 20; ++y) {
			for (int dir = 0; dir < 4; ++dir) {
				if (cache[x][y][dir] != -1)
					continue;
				if (map[x][y] == 0)
					continue;
				flag = true;
				cache[x][y][dir] = solve(x, y, dir, 1, map[x][y]);
			}
		}
	}

	int ax = 0, ay = 0;
	for (int x = 1; x < 20; ++x) {
		for (int y = 1; y < 20; ++y) {
			for (int dir = 0; dir < 4; ++dir) {
				if (cache[x][y][dir] == 5) {
					if (ax == 0 && ay == 0) {
						ax = x; ay = y;
					}
					else if (ay != y) {
						if (y < ay) {
							ax = x; ay = y;
						}
					}
				}
			}
		}
	}

	if (ans == 0)
		printf("%d\n", ans);
	else
		printf("%d\n%d %d\n", ans, ax, ay);


	return 0;
}