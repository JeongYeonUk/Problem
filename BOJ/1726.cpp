#include <iostream>
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

enum STATE {
	EAST = 0,
	WEST,
	SOUTH,
	NORTH
};

struct INFO {
	int y, x, dir, cnt;
};

int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX][4];
int chk[MAX][MAX];

int sy, sx, sdir;
int ey, ex, edir;

bool check(int cy, int cx, int ny, int nx, int dir) {
	switch (dir)
	{
	case EAST:
		for (int x = cx; x <= nx; ++x) {
			if (map[ny][x] == 1)
				return false;
		}
		break;
	case WEST:
		for (int x = cx; x >= nx; --x) {
			if (map[ny][x] == 1)
				return false;
		}
		break;
	case SOUTH:
		for (int y = cy; y <= ny; ++y) {
			if (map[y][nx] == 1)
				return false;
		}
		break;
	case NORTH:
		for (int y = cy; y >= ny; --y) {
			if (map[y][nx] == 1)
				return false;
		}
		break;
	default:
		break;
	}
	return true;
}

int bfs() {
	queue<INFO> q;
	q.push({ sy,sx,sdir,0 });
	visit[sy][sx][sdir] = true;

	while (!q.empty()) {
		INFO cur = q.front(); q.pop();
		if (cur.y == ey && cur.x == ex && cur.dir == edir) {
			
				return cur.cnt;
		}


		for (int k = 1; k <= 3; ++k) {
			int ny = cur.y + (dy[cur.dir] * k);
			int nx = cur.x + (dx[cur.dir] * k);

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (visit[ny][nx][cur.dir])
				continue;
			if (map[ny][nx])
				break;
			visit[ny][nx][cur.dir] = true;
			q.push({ ny,nx,cur.dir, cur.cnt + 1 });
		}

		for (int dir = 0; dir < 4; ++dir) {
			if ((cur.dir == dir) || visit[cur.y][cur.x][dir])
				continue;
			visit[cur.y][cur.x][dir] = true;
			if ((cur.dir == WEST && dir == EAST) || (cur.dir == NORTH && dir == SOUTH)
				|| (cur.dir == EAST && dir == WEST) || (cur.dir == SOUTH && dir == NORTH)) {
				q.push({ cur.y, cur.x, dir, cur.cnt + 2 });
			}
			else {
				q.push({ cur.y, cur.x, dir, cur.cnt + 1 });
			}
		}
	}
	return 0;
}

void print() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cout << chk[y][x] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> N >> M;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> map[y][x];
			chk[y][x] = map[y][x];
		}
	}

	cin >> sy >> sx >> sdir >> ey >> ex >> edir;
	sy -= 1;
	sx -= 1;
	sdir -= 1;
	ey -= 1;
	ex -= 1;
	edir -= 1;

	int ans = bfs();
	//print();
	cout << ans << endl;

	return 0;
}
