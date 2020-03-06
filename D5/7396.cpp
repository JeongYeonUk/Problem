#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX = 2000 + 1;
const int dy[] = { 1,0 };
const int dx[] = { 0,1 };

struct POS {
	int y, x;
};

char board[MAX][MAX];
bool visit[MAX][MAX];
int N, M;
string ans;

void bfs(int sy, int sx) {
	queue<POS> q;
	q.push({ sy,sx });
	visit[sy][sx] = true;
	ans += board[sy][sx];
	
	// 최소값 리스트
	vector<POS> list;

	while (!q.empty()) {
		int qSize = q.size();
		int min = INF;
		for (int i = 0; i < qSize; ++i) {
			int y = q.front().y; int x = q.front().x;
			q.pop();

			if (y == N - 1 && x == M - 1)
				return;
			for (int dir = 0; dir < 2; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M)
					continue;
				if (visit[ny][nx])
					continue;

				visit[ny][nx] = true;
				int next = board[ny][nx] - 'a';

				// 최소값 갱신
				if (next < min) {
					list.clear();
					min = next;
					list.push_back({ ny,nx });
				}
				// 최소값과 같다면
				else if (next == min) {
					list.push_back({ ny,nx });
				}
			}
		}
		// 최소값 리스트를 순회하면서 큐에 삽입
		for (int i = 0; i < list.size(); ++i) {
			int ny = list[i].y;
			int nx = list[i].x;
			q.push({ ny,nx });
		}
		ans += board[list[0].y][list[0].x];
		list.clear();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		memset(board, 0, sizeof(board));
		memset(visit, false, sizeof(visit));
		ans = "";
		cin >> N >> M;
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				cin >> board[y][x];
			}
		}

		bfs(0, 0);
		cout << "#" << t << " " << ans << endl;
	}

	return 0;
}