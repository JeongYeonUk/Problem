#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAXN = 100 + 1;
const int MAXK = 1000 + 1;
const int dy[] = { 0,-1,1,0,0 };
const int dx[] = { 0,0,0,-1,1 };

int bug[MAXK][4];
int bugMap[MAXN][MAXN][2];
int N, M, K;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> N >> M >> K;
		for (int k = 0; k < K; ++k) {
			cin >> bug[k][0] >> bug[k][1] >> bug[k][2] >> bug[k][3];
		}
		while (M--) {
			memset(bugMap, 0, sizeof(bugMap));
			for (int k = 0; k < K; ++k) {
				int dir = bug[k][3];
				if (dir == -1)
					continue;

				int& bugCnt = bug[k][2];
				int ny = bug[k][0] + dy[dir];
				int nx = bug[k][1] + dx[dir];

				if (ny == 0 || nx == 0 || ny == N - 1 || nx == N - 1) {
					bugCnt >>= 1;
					if (bugCnt == 0) {
						bug[k][3] = -1;
					}
					else {
						if (dir == 1) bug[k][3] = 2;
						else if (dir == 2) bug[k][3] = 1;
						else if (dir == 3) bug[k][3] = 4;
						else if (dir == 4) bug[k][3] = 3;
					}
				}
				else {
					if (!bugMap[ny][nx][1]) {
						bugMap[ny][nx][0] = bugCnt;
						bugMap[ny][nx][1] = dir;
					}
					else {
						for (int i = 0; i < k; ++i) {
							if (bug[i][3] != -1 && bug[i][0] == ny && bug[i][1] == nx) {
								bug[i][2] += bugCnt;

								if (bugCnt > bugMap[ny][nx][0]) {
									bug[i][3] = dir;
									bugMap[ny][nx][0] = bugCnt;
									bugMap[ny][nx][1] = dir;
								}
								bug[k][3] = -1;
								break;
							}
						}
					}
				}
				bug[k][0] = ny;
				bug[k][1] = nx;
			}
		}
		int ans = 0;
		for (int i = 0; i < K; ++i) {
			if (bug[i][3] != -1)
				ans += bug[i][2];
		}
		cout << "#" << t << " " << ans << endl;
	}

	return 0;
}