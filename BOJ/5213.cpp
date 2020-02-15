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
const int MAX = 500 + 5;

const int dy[] = { -1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,1,1,1,0,-1,-1,-1 };
enum STATE {
	UP,
	UPRIGHT,
	RIGHT,
	DOWNRIGHT,
	DOWN,
	DOWNLEFT,
	LEFT,
	UPLEFT
};

struct TILE {
	int l, r, tnum;
	TILE() {
		l = r = -1;
	}
};

struct INFO {
	int y, x, tnum;
};

TILE tile[MAX][MAX];
bool visit[MAX][MAX];

bool adj[MAX][MAX][8];
int path[MAX * MAX];
int st[MAX * MAX], top;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int n; cin >> n;
	int cnt = 1;
	for (int y = 1; y <= n; ++y) {
		for (int x = 1; x <= n - 1 + (y & 1); ++x) {
			cin >> tile[y][x].l >> tile[y][x].r;
			tile[y][x].tnum = cnt++;
		}
	}

	for (int y = 1; y <= n; ++y) {
		for (int x = 1; x <= n - 1 + (y & 1); ++x) {
			for (int dir = 0; dir < 8; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (tile[ny][nx].l == -1) 
					continue;
				switch (dir)
				{
				case UPRIGHT:
				case DOWNRIGHT:
					if ((y & 1) == 0) {
						adj[y][x][dir] = tile[y][x].r == tile[ny][nx].l;
					}
					break;
				case UP:
				case DOWN:
					if ((y & 1)) {
						adj[y][x][dir] = tile[y][x].r == tile[ny][nx].l;
					}
					else {
						adj[y][x][dir] = tile[y][x].l == tile[ny][nx].r;
					}
					break;
				case UPLEFT:
				case DOWNLEFT:
					if ((y & 1)) {
						adj[y][x][dir] = tile[y][x].l == tile[ny][nx].r;
					}
					break;
				case LEFT:
					adj[y][x][dir] = tile[y][x].l == tile[ny][nx].r;
					break;
				case RIGHT:
					adj[y][x][dir] = tile[y][x].r == tile[ny][nx].l;
					break;
				default:
					break;
				}
			}
		}
	}

	int max = 0;
	queue<INFO> q;
	q.push({ 1,1,1 });
	visit[1][1] = true;
	path[1] = 0;

	while (!q.empty()) {
		INFO cur = q.front(); q.pop();
		max = cur.tnum > max ? cur.tnum : max;

		for (int dir = 0; dir < 8; ++dir) {
			if (!adj[cur.y][cur.x][dir])
				continue;
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			int ntnum = tile[ny][nx].tnum;
			if (visit[ny][nx])
				continue;
			visit[ny][nx] = true;
			path[ntnum] = cur.tnum;
			q.push({ ny,nx,ntnum });

		}
	}

	int p = max;
	while (p) {
		st[top++] = p;
		p = path[p];
	}
	cout << top << endl;
	while (top) {
		cout << st[--top] << " ";
	}
	cout << endl;

	return 0;
}
