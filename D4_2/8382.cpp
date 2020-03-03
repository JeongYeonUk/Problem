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
const int MAX = 200 + 5;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

enum STATE {
	GARO,
	SERO
};

struct INFO {
	int x, y, state, cnt;
};

int board[MAX][MAX];
bool visit[MAX][MAX][2];
int sx, sy, ex, ey;
void init() {
	memset(board, 0, sizeof(board));
	memset(visit, false, sizeof(visit));
	sx = sy = ex = ey = 0;
}

bool isOut(int x, int y) {
	return x < 0 || y < 0 || x > 200 || y > 200;
}

int bfs() {
	queue<INFO> q;
	q.push({ sx,sy,GARO, 0 });
	q.push({ sx,sy,SERO, 0 });
	visit[sx][sy][GARO] = true;
	visit[sx][sy][SERO] = true;

	while (!q.empty()) {
		int x = q.front().x; int y = q.front().y; int state = q.front().state; int cnt = q.front().cnt;
		q.pop();

		if (x == ex && y == ey)
			return cnt;

		if (state == GARO) {
			for (int dir = 2; dir < 4; ++dir) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				int nstate = state ^ 1;
				int ncnt = cnt + 1;
				if (isOut(nx, ny) || visit[nx][ny][nstate])
					continue;
				visit[nx][ny][nstate] = true;
				q.push({ nx,ny, nstate, ncnt });
			}
		}
		else {
			for (int dir = 0; dir < 2; ++dir) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				int nstate = state ^ 1;
				int ncnt = cnt + 1;
				if (isOut(nx, ny) || visit[nx][ny][nstate])
					continue;
				visit[nx][ny][nstate] = true;
				q.push({ nx,ny,nstate,ncnt });
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		init();
		cin >> sx >> sy >> ex >> ey;
		sx += 100;	sy += 100;	ex += 100;	ey += 100;

		cout << '#' << t << ' ' << bfs() << endl;
	}

	return 0;
}
