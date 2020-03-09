#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 50 + 1;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct POS {
	int y, x;
};

struct INFO {
	int y, x, cnt;
};

char board[MAX][MAX];
bool visit[MAX][MAX];
int N, M;
POS src, dest;
queue<POS> hand;
bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= N || x >= M;
}

void print() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cout << board[y][x];
		}
		cout << endl;
	}
	cout << endl;
}

int bfs() {
	queue<INFO> yeon;

	yeon.push({ src.y, src.x, 0 });

	visit[src.y][src.x] = true;

	while (!yeon.empty()) {
		//print();
		int ySize = yeon.size();
		for (int i = 0; i < ySize; ++i) {
			int y = yeon.front().y; int x = yeon.front().x; int cnt = yeon.front().cnt;
			yeon.pop();
			if (y == dest.y && x == dest.x) {
				return cnt;
			}
			if (board[y][x] == '*')
				continue;
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				int ncnt = cnt + 1;
				if (isOut(ny, nx) || visit[ny][nx])
					continue;
				if (board[ny][nx] == '*' || board[ny][nx] == 'X')
					continue;
				if (board[ny][nx] == '.' || board[ny][nx] == 'D') {
					board[ny][nx] = 'S';
					yeon.push({ ny,nx,ncnt });
					visit[ny][nx] = true;
				}
			}
		}
		int hSize = hand.size();
		for (int i = 0; i < hSize; ++i) {
			int y = hand.front().y; int x = hand.front().x;
			hand.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (isOut(ny, nx))
					continue;
				if (board[ny][nx] == 'X' || board[ny][nx] == 'D')
					continue;
				if (board[ny][nx] == '.' || board[ny][nx] == 'S') {
					board[ny][nx] = '*';
					hand.push({ ny,nx });
				}
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> N >> M;
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				cin >> board[y][x];
				if (board[y][x] == 'S') {
					src = { y,x };
				}
				else if (board[y][x] == 'D') {
					dest = { y,x };
				}
				else if (board[y][x] == '*') {
					hand.push({ y,x });
				}
			}
		}
		
		memset(visit, false, sizeof(visit));
		int ret = bfs();
		cout << "#" << t << " ";
		if (ret == -1) {
			cout << "GAME OVER" << endl;
		}
		else {
			cout << ret << endl;
		}
		while (!hand.empty()) {
			hand.pop();
		}
	}

	return 0;
}