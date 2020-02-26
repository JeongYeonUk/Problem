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

const int hdy[] = { 2,1,-1,-2,-2,-1,1,2 };
const int hdx[] = { 1,2,2,1,-1,-2,-2,-1 };
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct INFO {
	int y, x, cnt, horse;
};

int N, M, K;
int board[MAX][MAX];
bool visit[MAX][MAX][30 + 2];

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= N || x >= M;
}

int bfs(int sy, int sx) {
	queue<INFO> q;
	q.push({ sy,sx,0,0 });
	visit[sy][sx][0] = true;

	while (!q.empty()) {
		int y = q.front().y; int x = q.front().x; int cnt = q.front().cnt; int horse = q.front().horse;
		q.pop();
		
		if (y == N - 1 && x == M - 1) {
			return cnt;
		}

		if (horse < K) {
			for (int dir = 0; dir < 8; ++dir) {
				int ny = y + hdy[dir];
				int nx = x + hdx[dir];
				int ncnt = cnt + 1;
				int nhorse = horse + 1;
				if (isOut(ny, nx))
					continue;
				if (board[ny][nx] == 1 || visit[ny][nx][nhorse])
					continue;
				q.push({ ny,nx,ncnt,nhorse });
				visit[ny][nx][nhorse] = true;
			}
		}

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			int ncnt = cnt + 1;
			int nhorse = horse;

			if (isOut(ny, nx))
				continue;
			if (board[ny][nx] == 1 || visit[ny][nx][nhorse])
				continue;
			q.push({ ny,nx,ncnt,nhorse });
			visit[ny][nx][nhorse] = true;
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> K >> M >> N;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	cout << bfs(0, 0) << endl;

	return 0;
}
