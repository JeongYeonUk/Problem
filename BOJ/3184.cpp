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
const int MAX = 250 + 5;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct POS {
	int y, x;
};

struct INFO {
	int sheep, wolf;
	INFO() {
		sheep = 0;
		wolf = 0;
	}
};

int N, M;
int allSheep, allWolf;

char board[MAX][MAX];
bool visit[MAX][MAX];

INFO bfs(int sy, int sx) {
	queue<POS> q;
	q.push({ sy, sx });
	visit[sy][sx] = true;

	INFO ret;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		if (board[y][x] == 'v') {
			ret.wolf++;
		}

		if (board[y][x] == 'o') {
			ret.sheep++;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;

			if (board[ny][nx] == '#' || visit[ny][nx])
				continue;

			visit[ny][nx] = true;
			q.push({ ny,nx });
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> N >> M;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (board[y][x] != '#' && !visit[y][x]) {
				INFO ret = bfs(y, x);
				if (ret.sheep > ret.wolf) {
					allSheep += ret.sheep;
				}
				else{
					allWolf += ret.wolf;
				}
			}
		}
	}

	cout << allSheep << " " << allWolf << endl;


	return 0;
}
