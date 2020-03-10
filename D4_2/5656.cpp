#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

/*
#1 12
#2 27
#3 4
#4 8
#5 0
*/

typedef long long ll;

const int INF = 987654321;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

int ball[5];
int board[16][13];
int backup[16][13];
int N, W, H, ans;

int q[1000][3];
int f, r;

void enq(int y, int x, int delta) {
	q[++r][0] = y;
	q[r][1] = x;
	q[r][2] = delta;
}

void init() {
	memset(ball, 0, sizeof(ball));
	memset(q, 0, sizeof(q));
	ans = INF;
	f = r = -1;
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= H || x >= W;
}

void copy(int dest[][13], int src[][13]) {
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			dest[y][x] = src[y][x];
		}
	}
}

void down() {
	int mboard[16][13];
	memset(mboard, 0, sizeof(mboard));
	int idx = H;
	for (int x = 0; x < W; ++x) {
		idx = H;
		for (int y = H - 1; y >= 0; --y) {
			if (board[y][x] != 0) {
				mboard[--idx][x] = board[y][x];
			}
		}
	}
	copy(board, mboard);
}

void bomb(int sx) {
	f = r = -1;
	for (int y = 0; y < H; ++y) {
		if (board[y][sx] != 0) {
			enq(y, sx, board[y][sx] - 1);
			board[y][sx] = 0;
			break;
		}
	}
	while (f != r) {
		int y = q[++f][0]; int x = q[f][1]; int delta = q[f][2];
		for (int dir = 0; dir < 4; ++dir) {
			int ny = y;
			int nx = x;
			for (int del = 0; del < delta; ++del) {
				ny += dy[dir];
				nx += dx[dir];
				if (isOut(ny, nx))
					continue;
				if (board[ny][nx] != 0)
					enq(ny, nx, board[ny][nx] - 1);
				board[ny][nx] = 0;
			}
		}
	}
	down();
}
int check() {
	int candi = 0;
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			if (board[y][x] != 0)
				candi++;
		}
	}
	return candi;
}

void solve(int cnt) {
	if (cnt == 0) {
		int candi = check();
		if (candi < ans)
			ans = candi;
		return;
	}

	int mboard[16][13];
	copy(mboard, board);
	for (int i = 0; i < W; ++i) {
		bomb(i);
		solve(cnt - 1);
		copy(board, mboard);
	}

}

int main() {

	//freopen("input.txt", "r", stdin);

	int tc; scanf("%d", &tc);

	for (int t = 1; t <= tc; ++t) {
		init();
		scanf("%d %d %d", &N, &W, &H);
		for (int y = 0; y < H; ++y) {
			for (int x = 0; x < W; ++x) {
				scanf("%d", &board[y][x]);
			}
		}
		solve(N);
		printf("#%d %d\n", t, ans);
	}
	return 0;
}