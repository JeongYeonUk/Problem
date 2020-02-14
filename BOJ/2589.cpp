#pragma warning(disable:4996)
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
const int MAX = 50 + 5;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct INFO {
	int y, x;
};

char map[MAX][MAX];

int N, M, ans;

void bfs(int sy, int sx) {
	bool visit[MAX][MAX];
	int cache[MAX][MAX];
	memset(visit, false, sizeof(visit));
	memset(cache, 0, sizeof(cache));
	queue<INFO> q;
	q.push({ sy, sx });
	while (!q.empty()) {
		INFO cur = q.front(); q.pop();
		visit[cur.y][cur.x] = true;
		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (map[ny][nx] == 'W' || visit[ny][nx])
				continue;
			visit[ny][nx] = true;
			cache[ny][nx] = cache[cur.y][cur.x] + 1;
			q.push({ ny,nx });
		}
	}
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (ans < cache[y][x]) {
				ans = cache[y][x];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> N >> M;
	for (int y = 0; y < N; ++y) {
		string s; cin >> s;
		for (int x = 0; x < M; ++x) {
			map[y][x] = s[x];
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (map[y][x] == 'L')
				bfs(y, x);
		}
	}
	cout << ans << endl;
	return 0;
}
