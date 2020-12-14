#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'
#define INF 987654321

int grid[501][501];
int H, W;

void fill_water()
{
	for (int y = 0; y < W; ++y) {
		for (int x = 0; x < H; ++x) {
			grid[y][x] = (grid[y][x] == 0 ? 2 : grid[y][x]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> H >> W;

	int wall;
	for (int i = 0; i < W; ++i) {
		cin >> wall;
		for (int w = 0; w < wall; ++w) {
			grid[i][w] = 1;
		}
	}

	fill_water();

	for (int y = 0; y < W; ++y) {
		for (int x = H - 1; x >= 0; --x) {
			if (grid[y][x] == 1) continue;
			if (y - 1 < 0) {
				grid[y][x] = 0;
				continue;
			}

			if (grid[y - 1][x] == 0) {
				grid[y][x] = 0;
				continue;
			}
		}
	}

	for (int y = W - 1; y >= 0; --y) {
		for (int x = H - 1; x >= 0; --x) {
			if (grid[y][x] == 1) continue;
			if (y + 1 >= W) {
				grid[y][x] = 0;
				continue;
			}

			if (grid[y + 1][x] == 0) {
				grid[y][x] = 0;
				continue;
			}
		}
	}

	int ans = 0;
	for (int y = 0; y < W; ++y) {
		for (int x = 0; x < H; ++x) {
			ans += (grid[y][x] == 2 ? 1 : 0);
		}
	}
	cout << ans << endl;

	return 0;
}
