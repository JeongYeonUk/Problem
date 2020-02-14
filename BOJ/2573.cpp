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
const int MAX = 300 + 5;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct INFO {
	int y, x;
};

int map[MAX][MAX];
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> N >> M;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> map[y][x];
		}
	}

	int day = 0;
	int cluster = -1;
	while (true) {
		if (cluster == 0) {
			day = 0;
			break;
		}
		if (cluster > 1)
			break;

		int copy[MAX][MAX];
		memset(copy, 0, sizeof(copy));
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				copy[y][x] = map[y][x];
			}
		}

		for (int y = 1; y <= N; ++y) {
			for (int x = 1; x <= M; ++x) {
				if (map[y][x] != 0) {
					int cnt = 0;
					for (int dir = 0; dir < 4; ++dir) {
						int ny = y + dy[dir];
						int nx = x + dx[dir];
						if (map[ny][nx] == 0) {
							cnt++;
						}
					}
					if (map[y][x] - cnt < 0) {
						copy[y][x] = 0;
					}
					else {
						copy[y][x] = map[y][x] - cnt;
					}
				}
			}
		}
		
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				map[y][x] = copy[y][x];
			}
		}

		

		bool visit[MAX][MAX];
		memset(visit, false, sizeof(visit));
		cluster = 0;
		for (int y = 1; y <= N; ++y) {
			for (int x = 1; x <= M; ++x) {
				if (map[y][x] != 0 && !visit[y][x]) {
					cluster++;
					queue<INFO> q;
					q.push({ y, x });
					visit[y][x] = true;
					while (!q.empty()) {
						INFO cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; ++dir) {
							int ny = cur.y + dy[dir];
							int nx = cur.x + dx[dir];
							if (map[ny][nx] != 0 && !visit[ny][nx]) {
								q.push({ ny, nx });
								visit[ny][nx] = true;
							}
						}
					}

				}
			}
		}
		day++;
	}

	
	
	cout << day << endl;
	return 0;
}
