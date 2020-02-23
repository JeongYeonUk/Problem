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
const int MAX = 20 + 5;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct INFO {
	int dust, y, x;
};

int map[MAX][MAX];
int visit[MAX][MAX][1 << 11];
int n, m;

void print(int out[][MAX]) {
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			cout << out[y][x];
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	while (true) {
		queue<INFO> q;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		cin >> m >> n;
		if (n == 0 && m == 0)
			break;
		int cnt = 0;
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < m; ++x) {
				char ch; cin >> ch;
				if (ch == 'o') {
					q.push({ 0,y,x });
				}
				else if (ch == '*') {
					cnt++;
					map[y][x] = cnt;
				}
				else if (ch == 'x') {
					map[y][x] = -1;
				}
			}
		}
		//print(map);
		int all = (1 << cnt) - 1;
		bool check = false;
		while (!q.empty()) {
			INFO cur = q.front(); q.pop();
			if (cur.dust == all) {
				cout << visit[cur.y][cur.x][cur.dust] << endl;
				check = true;
				break;
			}
			for (int dir = 0; dir < 4; ++dir) {
				int ny = cur.y + dy[dir];
				int nx = cur.x + dx[dir];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;
				if (map[ny][nx] == -1)
					continue;
				if (map[ny][nx] == 0) {
					if (!visit[ny][nx][cur.dust]) {
						q.push({ cur.dust, ny, nx });
						visit[ny][nx][cur.dust] = visit[cur.y][cur.x][cur.dust] + 1;
					}
				}
				else if(map[ny][nx] > 0){
					if (!visit[ny][nx][cur.dust | (1 << (map[ny][nx] - 1))]) {
						q.push({ cur.dust | (1 << (map[ny][nx] - 1)) , ny, nx });
						visit[ny][nx][cur.dust | (1 << (map[ny][nx] - 1))] = visit[cur.y][cur.x][cur.dust] + 1;
					}
				}
			}
		}
		if (!check)
			cout << -1 << endl;
	}

	return 0;
}
