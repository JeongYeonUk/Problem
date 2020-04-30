#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct INFO {
	int y, x;
	int time;
};

int map[1001][1001];
int n, m, k, ans;


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		memset(map, 0, sizeof(map));
		ans = 0;
		cin >> n >> m >> k;

		queue<INFO> q[11];

		for (int y = 500; y < n + 500; ++y) {
			for (int x = 500; x < m + 500; ++x) {
				cin >> map[y][x];
				if (map[y][x])
					// 초기 상태에서 죽을 때까지 소요 시간은
					// 초기 시간 * 2
					q[map[y][x]].push(INFO{ y,x, map[y][x] << 1 });
			}
		}

		while (k--) {
			for (int i = 10; i > 0; --i) {
				for (int j = 0, size = (int)q[i].size(); j < size; ++j) {
					int y = q[i].front().y;
					int x = q[i].front().x;
					int time = q[i].front().time;
					q[i].pop();

					time--;

					// 초기시간보다 작아지는 경우 활성화
					if (map[y][x] > time) {
						for (int dir = 0; dir < 4; ++dir) {
							int ny = y + dy[dir];
							int nx = x + dx[dir];
							if (map[ny][nx] == 0) {
								map[ny][nx] = map[y][x];
								q[i].push(INFO{ ny,nx, map[ny][nx] << 1 });
							}
						}
					}

					// 아직 살아있으므로 다시 넣어준다.
					if (time > 0) {
						q[i].push(INFO{ y,x,time });
					}
				}
			}
		}

		for (int i = 1; i < 11; ++i)
			ans += q[i].size();
		cout << '#' << t << ' ' << ans << endl;
	}

	return 0;
}
