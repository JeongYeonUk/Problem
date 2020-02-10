#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 100 + 5;

int n, m;
int map[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> n >> m;
	for (int y = 1; y <= n; ++y) {
		for (int x = 1; x <= n; ++x) {
			map[y][x] = (y == x) ? 0 : INF;
		}
	}

	while (m--) {
		int a, b; cin >> a >> b;
		map[a][b] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (map[j][k] > map[j][i] + map[i][k]) {
					map[j][k] = map[j][i] + map[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			if (!(map[i][j] != INF || map[j][i] != INF)) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}
