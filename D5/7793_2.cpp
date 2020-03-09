#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <malloc.h>
using namespace std;

#define rint register int
#define ll long long

const int INF = 987654321;
const int MAX = 50 + 1;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct POS {
	int y, x;
};

char board[MAX][MAX];
int visit[MAX][MAX];
int N, M, ret, ny, nx, y, x, ySize, hSize;
POS src, dest;

int hand[MAX * MAX][2];
int hf, hr, yf, yr;

inline void enqueue(int queue[][2], int& r, int y, int x) {
	queue[++r][0] = y;
	queue[r][1] = x;
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= N || x >= M;
}

int bfs() {
	int yeon[MAX * MAX][2];
	yf = yr = -1;
	
	enqueue(yeon, yr, src.y, src.x);
	visit[src.y][src.x] = 1;

	while (yf != yr) {
		ySize = (yr - yf);
		for (rint i = 0; i < ySize; ++i) {
			y = yeon[++yf][0]; x = yeon[yf][1];
			if (y == dest.y && x == dest.x) {
				return visit[y][x] - 1;
			}
			if (board[y][x] == '*')
				continue;
			for (rint dir = 0; dir < 4; ++dir) {
				ny = y + dy[dir];
				nx = x + dx[dir];

				if (isOut(ny, nx) || visit[ny][nx])
					continue;
				if (board[ny][nx] == 'X' || board[ny][nx] == '*')
					continue;
				if (board[ny][nx] == '.' || board[ny][nx] == 'D') {
					visit[ny][nx] = visit[y][x] + 1;
					board[ny][nx] = 'S';
					enqueue(yeon, yr, ny, nx);
				}
			}
		}

		hSize = (hr - hf);
		for (rint i = 0; i < hSize; ++i) {
			y = hand[++hf][0]; x = hand[hf][1];
			for (rint dir = 0; dir < 4; ++dir) {
				ny = y + dy[dir];
				nx = x + dx[dir];

				if (isOut(ny, nx) || board[ny][nx] == 'X' || board[ny][nx] == 'D' || board[ny][nx] == '*')
					continue;
				board[ny][nx] = '*';
				enqueue(hand, hr, ny, nx);
			}
		}
	}
	return -1;
}

void init() {
	hr = hf = -1;
	for (rint y = 0; y < N; ++y) {
		for (rint x = 0; x < M; ++x) {
			visit[y][x] = 0;
		}
	}
}

int main() {
	int tc; scanf("%d", &tc);
	
	for (rint t = 1; t <= tc; ++t) {
		scanf("%d %d", &N, &M);
		init();
		for (rint y = 0; y < N; ++y) {
			for (rint x = 0; x < M; ++x) {
				scanf(" %1c", &board[y][x]);
				if (board[y][x] == 'S') {
					src = { y,x };
				}
				else if (board[y][x] == 'D') {
					dest = { y,x };
				}
				else if (board[y][x] == '*') {
					enqueue(hand, hr, y, x);
				}
			}
		}

		ret = bfs();
		printf("#%d ", t);
		if (ret == -1) {
			printf("GAME OVER\n");
		}
		else {
			printf("%d\n", ret);
		}

	}

	return 0;
}