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
const int MAX = 1000 + 5;
const int MAXK = 10 + 5;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct INFO {
	int y, x, wall, cnt;
};

char board[MAX][MAX];
bool visit[MAX][MAX][MAXK];

int N, M, K;
int ans;

void bfs(int sy, int sx) {
	queue<INFO> q;
	q.push({ sy,sx,0,1 });
	visit[sy][sx][0] = 1;

	while (!q.empty()) {
		int y = q.front().y; int x = q.front().x; int wall = q.front().wall; int cnt = q.front().cnt;
		q.pop();

		if (y == N - 1 && x == M - 1) {
			if (ans > cnt) {
				ans = cnt;
			}
			continue;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			int nwall = wall;
			int ncnt = cnt;

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (board[ny][nx] == '1') {
				if (nwall == K)
					continue;
				if (!visit[ny][nx][nwall]) {
					q.push({ ny,nx,nwall + 1,ncnt + 1 });
					visit[ny][nx][nwall] = true;
				}
			}
			else if (board[ny][nx] == '0') {
				if (!visit[ny][nx][nwall]) {
					q.push({ ny,nx,nwall, ncnt + 1 });
					visit[ny][nx][nwall] = true;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	ans = INF;
	bfs(0, 0);
	if (ans == INF) {
		cout << "-1\n";
	}
	else {
		cout << ans << endl;
	}

	return 0;
}