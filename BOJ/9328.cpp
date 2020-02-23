#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 100 + 5;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct INFO {
	int y, x;
};

int N, M, ans;
char map[MAX][MAX];
bool visit[MAX][MAX];
bool key[MAX];
string sKey;

void init() {
	memset(map, '\0', sizeof(map));
	memset(visit, false, sizeof(visit));
	memset(key, false, sizeof(key));
	sKey = "";
	ans = 0;
}

void bfs(int sy, int sx) {
	queue<INFO> q;
	queue<INFO> door[26];
	q.push({ sy, sx });
	visit[sy][sx] = true;
	while (!q.empty()) {
		INFO cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			if (ny < 0 || nx < 0 || ny > N + 1 || nx > M + 1)
				continue;
			if (map[ny][nx] == '*' || visit[ny][nx])
				continue;
			visit[ny][nx] = true;
			if ('A' <= map[ny][nx] && map[ny][nx] <= 'Z') {
				if (key[map[ny][nx] - 'A']) {
					q.push({ ny,nx });
				}
				else {
					door[map[ny][nx] - 'A'].push({ ny,nx });
				}
			}
			else if ('a' <= map[ny][nx] && map[ny][nx] <= 'z') {
				q.push({ ny,nx });
				if (key[map[ny][nx] - 'a'])
					continue;
				key[map[ny][nx] - 'a'] = true;
				while (!door[map[ny][nx] - 'a'].empty()) {
					q.push(door[map[ny][nx] - 'a'].front());
					door[map[ny][nx] - 'a'].pop();
				}
			}
			else {
				q.push({ ny,nx });
				if (map[ny][nx] == '$')
					ans++;
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		init();
		cin >> N >> M;
		for (int y = 1; y <= N; ++y) {
			for (int x = 1; x <= M; ++x) {
				cin >> map[y][x];
			}
		}
		cin >> sKey;
		for (int i = 0; i < sKey.length(); ++i) {
			if (sKey[i] == '0') continue;
			key[sKey[i] - 'a'] = true;
		}

		bfs(0, 0);
		cout << ans << endl;
	}

	return 0;
}
