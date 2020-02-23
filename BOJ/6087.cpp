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

struct POS {
	int y, x;
};

struct INFO {
	int y, x, dir, cnt;
};

int N, M;
char map[MAX][MAX];
int visit[MAX][MAX];

POS src, dest;

int bfs() {
	queue<INFO> q;
	for (int dir = 0; dir < 4; ++dir) {
		q.push({ src.y, src.x, dir, 0 });
	}
	visit[src.y][src.x] = 0;
	while (!q.empty()) {
		INFO cur = q.front(); q.pop();
		//cout << cur.y << " " << cur.x << " " << cur.dir << " " << cur.cnt << endl;
		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			int nCnt = cur.cnt;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (map[ny][nx] == '*')
				continue;
			if (dir != cur.dir)
				nCnt += 1;
			if (visit[ny][nx] >= nCnt) {
				visit[ny][nx] = nCnt;
				q.push({ ny,nx,dir,nCnt });
				//cout << ny << " " << nx << " " << dir << " " << nCnt << endl;
			}
		}
	}
	return visit[dest.y][dest.x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> M >> N;
	int cnt = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> map[y][x];
			if (map[y][x] == 'C') {
				if (cnt == 0) {
					src.y = y;
					src.x = x;
					cnt++;
				}
				else {
					dest.y = y;
					dest.x = x;
				}
			}
			visit[y][x] = INF;
		}
	}
	cout << bfs() << endl;

	
	return 0;
}
