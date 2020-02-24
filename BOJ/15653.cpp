#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 10 + 1;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct INFO {
	int ry, rx, by, bx, cnt;
};

int N, M;
int ry, rx, by, bx;
char board[MAX][MAX];
int visit[MAX][MAX][MAX][MAX];

int calDist(int ry, int rx, int by, int bx) {
	return abs(ry - by) + abs(rx - bx);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	queue<INFO> ball;

	cin >> N >> M;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
			if (board[y][x] == 'R') {
				ry = y; rx = x;
				board[y][x] = '.';
			}
			if (board[y][x] == 'B') {
				by = y; bx = x;
				board[y][x] = '.';
			}
		}
	}

	visit[ry][rx][by][bx] = true;
	ball.push({ ry,rx,by,bx,0 });
	while (!ball.empty()) {		
			int ry = ball.front().ry;	int rx = ball.front().rx;
			int by = ball.front().by;	int bx = ball.front().bx;
			int cnt = ball.front().cnt;
			ball.pop();
			for (int dir = 0; dir < 4; ++dir) {

				bool redflag, blueflag;
				redflag = blueflag = false;

				int nry = ry + dy[dir];
				int nrx = rx + dx[dir];
				int nby = by + dy[dir];
				int nbx = bx + dx[dir];
				int nCnt = cnt + 1;

				while (true) {
					if (board[nry][nrx] == '#') {
						nry -= dy[dir];
						nrx -= dx[dir];
						break;
					}
					if (board[nry][nrx] == 'O') {
						redflag = true;
						break;
					}
					nry += dy[dir]; nrx += dx[dir];
				}
				while (true) {
					if (board[nby][nbx] == '#') {
						nby -= dy[dir];
						nbx -= dx[dir];
						break;
					}
					if (board[nby][nbx] == 'O') {
						blueflag = true;
						break;
					}
					nby += dy[dir]; nbx += dx[dir];
				}

				if (blueflag)
					continue;
				if (redflag) {
					cout << nCnt << endl;
					return 0;
				}

				if (nry == nby && nrx == nbx) {
					int redDist = calDist(ry, rx, nry, nrx);
					int blueDist = calDist(by, bx, nby, nbx);

					if (redDist > blueDist) {
						nry -= dy[dir];
						nrx -= dx[dir];
					}
					else {
						nby -= dy[dir];
						nbx -= dx[dir];
					}
				}

				if (visit[nry][nrx][nby][nbx])
					continue;
				ball.push({ nry,nrx,nby,nbx, nCnt });
				visit[nry][nrx][nby][nbx] = true;
			}
	}
	cout << -1 << endl;

	return 0;
}
