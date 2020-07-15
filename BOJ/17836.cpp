#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct INFO {
	int y, x;
	bool sword;
	int time;
};

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };
const int maxNM = 100 + 5;

int board[maxNM][maxNM];
bool visit[maxNM][maxNM][2];
int N, M, T;

int bfs(int sy, int sx) {
	queue<INFO> q;
	q.push({ sy, sx, false, 0 });
	visit[sy][sx][false] = true;

	while (!q.empty()) {
		int y = q.front().y; int x = q.front().x; 
		bool sword = q.front().sword; int time = q.front().time;
		q.pop();

		if (y == N && x == M) {
			if (time <= T) return time;
			else continue;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			int ntime = time + 1;

			if (ny <= 0 || nx <= 0 || ny > N || nx > M) continue;
			if (visit[ny][nx][sword]) continue;
			if (!sword && board[ny][nx] == 1) continue;

			if (sword && board[ny][nx] == 1) {
				q.push({ ny, nx, sword, ntime });
				visit[ny][nx][sword] = true;
				continue;
			}

			if (board[ny][nx] == 2) {
				q.push({ ny,nx,!sword, ntime });
				visit[ny][nx][!sword] = true;
				continue;
			}

			if (board[ny][nx] == 0) {
				q.push({ ny,nx,sword,ntime });
				visit[ny][nx][sword] = true;
				continue;
			}
		}
	}

	return INF;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M >> T;

	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= M; ++x) {
			cin >> board[y][x];
		}
	}
	int ans = bfs(1, 1);
	if (ans == INF) cout << "Fail" << endl;
	else cout << ans << endl;

	return 0;
}
