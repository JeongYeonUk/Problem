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
const int dy[] = { 0,-1,0,1 };
const int dx[] = { -1,0,1,0 };

struct POS {
	int y, x;
};

int N, M, area;
int board[MAX][MAX];
bool visit[MAX][MAX];

int bfs(int sy, int sx) {
	queue<POS> q;
	q.push({ sy,sx });
	visit[sy][sx] = true;
	int cnt = 1;
	while (!q.empty()) {
		int y = q.front().y; int x = q.front().x;
		q.pop();

		int bit = 1;
		for (int dir = 0; dir < 4; ++dir) {
			if (!(board[y][x] & bit)) {

				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (0 <= ny && ny < N && 0 <= nx && nx < M) {
					if (!visit[ny][nx]) {
						cnt++;
						visit[ny][nx] = true;
						q.push({ ny,nx });
					}
				}
			}
			bit <<= 1;
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> M >> N;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	int cnt = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (visit[y][x])
				continue;
			area = max(area, bfs(y, x));
			cnt++;
		}
	}

	cout << cnt << endl << area << endl;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			for (int bit = 1; bit <= 8; bit <<= 1) {
				if (board[y][x] & bit) {
					memset(visit, false, sizeof(visit));
					board[y][x] ^= bit;
					area = max(area, bfs(y, x));
					board[y][x] |= bit;
				}
			}
		}
	}
	cout << area << endl;
	return 0;
}
