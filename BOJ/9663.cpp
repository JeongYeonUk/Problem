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

bool grid[15][15];
int N;
int ans;

bool is_valid(int sy, int sx)
{
	for (int x = 0; x < sx; ++x) {
		if (grid[sy][x]) return false;
	}

	for (int x = sx - 1, y = sy - 1; y >= 0; --x, --y) {
		if (grid[y][x]) return false;
	}

	for (int x = sx - 1, y = sy + 1; y < N; --x, ++y) {
		if (grid[y][x]) return false;
	}
	return true;
}

void dfs(int x)
{
	if (x == N) {
		ans++;
		return;
	}
	for (int y = 0; y < N; ++y) {
		if (!grid[y][x] && is_valid(y, x)) {
			grid[y][x] = true;
			dfs(x + 1);
			grid[y][x] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N;

	dfs(0);
	cout << ans << endl;

	return 0;
}
