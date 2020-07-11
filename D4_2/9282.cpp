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

const int maxN = 50 + 1;

int n, m;
int choco[maxN][maxN];
int sum[maxN][maxN];
int dp[maxN][maxN][maxN][maxN];

int solve(int sy, int sx, int ey, int ex)
{
	if (ey == sy && ex == sx) return 0;

	int& ret = dp[sy][sx][ey][ex];
	if (ret != -1) return ret;

	int temp = sum[ey][ex] - sum[sy - 1][ex] - sum[ey][sx - 1] + sum[sy - 1][sx - 1];

	int imin = INF;

	for (int x = sx; x < ex; ++x) {
		imin = min(imin, temp + (solve(sy, sx, ey, x) + solve(sy, x + 1, ey, ex)));
	}

	for (int y = sy; y < ey; ++y) {
		imin = min(imin, temp + (solve(sy, sx, y, ex) + solve(y + 1, sx, ey, ex)));
	}

	return ret = imin;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> n >> m;
		for (int y = 1; y <= n; ++y) {
			for (int x = 1; x <= m; ++x) {
				cin >> choco[y][x];
			}
		}

		memset(dp, -1, sizeof(dp));

		// 누적 합을 미리 구해 놓는다.
		for (int y = 1; y <= n; ++y) {
			for (int x = 1; x <= m; ++x) {
				sum[y][x] = sum[y - 1][x] + sum[y][x - 1] - sum[y - 1][x - 1] + choco[y][x];
			}
		}

		int ans = solve(1, 1, n, m);
		cout << '#' << t << ' ' << ans << endl;
	}

	return 0;
}
