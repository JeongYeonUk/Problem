#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int board[41][41];
int sti[11][11];
int N, M, K, R, C;

void rotate() {
	int tmp[12][12] = { 0, };

	for (int c = 0; c < C; ++c) {
		for (int r = 0; r < R; ++r) {
			tmp[c][r] = sti[R - r - 1][c];
		}
	}

	for (int c = 0; c < C; ++c) {
		for (int r = 0; r < R; ++r) {
			sti[c][r] = tmp[c][r];
		}
	}

	swap(R, C);
}

void print() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cout << board[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isPossble() {
	for (int y = 0; y < N; ++y) {
		bool flag = true;
		for (int x = 0; x < M; ++x) {
			flag = true;
			for (int r = 0; r < R; ++r) {
				for (int c = 0; c < C; ++c) {
					if ((y + r) >= N || (x + c) >= M) {
						flag = false;
						break;
					}
					if (board[y + r][x + c] == 1 && sti[r][c] == 1) {
						flag = false;
						break;
					}
				}
				if (!flag)
					break;
			}

			if (!flag) continue;

			for (int r = 0; r < R; ++r) {
				for (int c = 0; c < C; ++c) {
					if(!board[y+r][x+c])
					board[y + r][x + c] = sti[r][c];
				}
			}
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	while (K--) {
		cin >> R >> C;
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				cin >> sti[r][c];
			}
		}

		//print();
		if (isPossble()) continue;
		rotate(); // 90
		if (isPossble()) continue;
		rotate(); // 180
		if (isPossble()) continue;
		rotate(); // 270
		if (isPossble()) continue;
	}

	//print();

	int ans = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (board[y][x])
				ans++;
		}
	}
	cout << ans << endl;

	return 0;
}