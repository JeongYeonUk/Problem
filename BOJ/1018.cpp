#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
char grid[51][51];

int solve(int sy, int sx)
{
	string white[] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
	};
	string black[] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
	};

	int black_candi = 0;
	int white_candi = 0;
	for (int y = 0; y < 8; ++y) {
		for (int x = 0; x < 8; ++x) {
			if (black[y][x] != grid[sy + y][sx + x]) black_candi++;
			if (white[y][x] != grid[sy + y][sx + x]) white_candi++;
		}
	}
	return min(black_candi, white_candi);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M;
	string input;
	for (int y = 0; y < N; ++y) {
		cin >> input;
		for (int x = 0; x < M; ++x) {
			grid[y][x] = input[x];
		}
	}

	int ans = INF;
	for (int y = 0; y < N; ++y) {
		if (y + 7 >= N) break;
		for (int x = 0; x < M; ++x) {
			if (x + 7 >= M) break;
			int candi = solve(y, x);
			ans = min(ans, candi);
		}
	}
	cout << ans << endl;

	return 0;
}
