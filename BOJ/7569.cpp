#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 100 + 5;

const int dz[] = {0,0,0,0,1,-1};
const int dy[] = {0,0,-1,1,0,0};
const int dx[] = {1,-1,0,0,0,0};

struct INFO {
	int z, y, x;
};

int M, N, H;
int map[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];

queue<INFO> q;

bool check() {
	
	for (int h = 0; h < H; ++h) {
		for (int n = 0; n < N; ++n) {
			for (int m = 0; m < M; ++m) {
				if (map[h][n][m] == 0)
					return false;
			}
		}
	}
	return true;
}

int bfs() {
	int day = 1;
	while (!q.empty()) {
		int size = (int)q.size();
		for (int i = 0; i < size; ++i) {
			INFO cur = q.front(); q.pop();
			visit[cur.z][cur.y][cur.x] = true;
			for (int dir = 0; dir < 6; ++dir) {
				int nz = cur.z + dz[dir];
				int ny = cur.y + dy[dir];
				int nx = cur.x + dx[dir];
				if (ny < 0 || nx < 0 || nz < 0 || ny >= N || nx >= M || nz >= H)
					continue;
				if (visit[nz][ny][nx] || map[nz][ny][nx] != 0)
					continue;
				map[nz][ny][nx] = 1;
				visit[nz][ny][nx] = true;
				q.push({ nz,ny,nx });
			}
			if (check()) {
				return day;
			}
		}
		day++;
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> M >> N >> H;
	int notoma = 0;
	for (int h = 0; h < H; ++h) {
		for (int n = 0; n < N; ++n) {
			for (int m = 0; m < M; ++m) {
				cin >> map[h][n][m];
				if (map[h][n][m] == 1) {
					q.push({ h,n,m });
				}
				else if (map[h][n][m] == 0) {
					notoma++;
				}
			}
		}
	}
	if (notoma == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << bfs() << endl;
	return 0;
}
