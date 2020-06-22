#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

struct Fish {
	int idx, dir;
	int y, x;
};

int ans;
Fish shark;
Fish fish[17];
int board[5][5];

void solve(Fish fish[17], int board[5][5], Fish shark, int total)
{
	ans = max(ans, total);

	for (int i = 1; i <= 16; ++i)
	{
		int y = fish[i].y;
		int x = fish[i].x;
		int dir = fish[i].dir;

		if (dir == 0) continue;

		int ny = y + dy[dir];
		int nx = x + dx[dir];

		int dirCnt = 0;
		for (; dirCnt < 8; ++dirCnt) {
			ny = y + dy[dir];
			nx = x + dx[dir];

			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) {
				fish[i].dir = (dir == 8) ? 1 : dir + 1;
				dir = fish[i].dir;
				continue;
			}

			if (ny == shark.y && nx == shark.x) {
				fish[i].dir = (dir == 8) ? 1 : dir + 1;
				dir = fish[i].dir;
				continue;
			}
			break;
		}

		// 이동할 곳이 없으므로
		if (dirCnt == 8) continue;

		int nIdx = board[ny][nx];

		if (nIdx) {
			fish[nIdx].y = y;
			fish[nIdx].x = x;
			board[y][x] = nIdx;
		}
		else {
			board[y][x] = 0;
		}

		fish[i].y = ny;
		fish[i].x = nx;
		board[ny][nx] = i;
	}

	int y = shark.y;
	int x = shark.x;
	int dir = shark.dir;

	for (int i = 1; i <= 3; ++i) {
		Fish tFish[17];
		for (int idx = 0; idx < 17; ++idx) {
			tFish[idx] = fish[idx];
		}

		int tBoard[5][5];

		for (int y = 0; y < 4; ++y) {
			for (int x = 0; x < 4; ++x) {
				tBoard[y][x] = board[y][x];
			}
		}

		int ny = y + (dy[dir] * i);
		int nx = x + (dx[dir] * i);

		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
		if (tBoard[ny][nx] == 0) continue;

		shark.y = ny;
		shark.x = nx;

		int score = tBoard[ny][nx];
		tBoard[ny][nx] = 0;

		shark.dir = tFish[score].dir;
		tFish[score].dir = 0;

		solve(tFish, tBoard, shark, total + score);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			int idx, dir; cin >> idx >> dir;
			if (y == 0 && x == 0) {
				shark = { idx, dir ,y , x };
				continue;
			}

			fish[idx] = { idx, dir, y, x };
			board[y][x] = idx;
		}
	}

	solve(fish, board, shark, shark.idx);

	cout << ans << endl;

	return 0;
}
