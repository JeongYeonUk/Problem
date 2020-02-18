#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 100 + 5;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct INFO {
	int y, x;
};

int N, M;
char map[MAX][MAX];
int cache[MAX][MAX][3];
deque<INFO> dq;

void bfs() {
	dq.push_back({ 0,0 });
	for (int k = 0; k < 3; ++k) {
		int sx = dq.back().x, sy = dq.back().y; dq.pop_back();
		deque<INFO> q;
		q.push_back({ sy, sx });
		cache[sy][sx][k] = 0;
		while (!q.empty()) {
			INFO cur = q.front(); q.pop_front();
			for (int dir = 0; dir < 4; ++dir) {
				int ny = cur.y + dy[dir];
				int nx = cur.x + dx[dir];
				if (nx < 0 || ny < 0 || nx > M + 1 || ny > N + 1)
					continue;
				if (cache[ny][nx][k] >= 0 || map[ny][nx] == '*')
					continue;
				if (map[ny][nx] == '.') {
					cache[ny][nx][k] = cache[cur.y][cur.x][k];
					q.push_front({ ny,nx });
				}
				else if (map[ny][nx] == '#') {
					cache[ny][nx][k] = cache[cur.y][cur.x][k] + 1;
					q.push_back({ ny,nx });
				}
			}
		}
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		memset(cache, -1, sizeof(cache));
		scanf("%d %d", &N, &M);
		for (int y = 0; y < N + 2; ++y) {
			for (int x = 0; x < M + 2; ++x) {
				if (y == 0 || y == N + 1 || x == 0 || x == M + 1)
					map[y][x] = '.';
				else
					scanf(" %1c", &map[y][x]);
				if (map[y][x] == '$') {
					map[y][x] = '.';
					dq.push_back({ y,x });
				}
			}
		}
		bfs();
		int ans = INF;
		for (int y = 0; y < N + 2; ++y) {
			for (int x = 0; x < M + 2; ++x) {
				if (map[y][x] == '*')
					continue;
				int k = cache[y][x][0] + cache[y][x][1] + cache[y][x][2];
				if (map[y][x] == '#')
					k -= 2;
				if (ans > k)
					ans = k;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
