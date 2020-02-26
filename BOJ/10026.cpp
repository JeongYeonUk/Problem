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

char board[MAX][MAX];
char nboard[MAX][MAX];
bool visit[MAX][MAX];
int N;

struct INFO {
	int y, x;
};

void bfs(int sy, int sx, char ch, char map[][MAX]) {
	queue<INFO> q;
	q.push({ sy,sx });
	visit[sy][sx] = true;

	while (!q.empty()) {
		int y = q.front().y; int x = q.front().x;
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visit[ny][nx] || map[ny][nx] != ch) {
				continue;
			}

			visit[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);
	
	cin >> N;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> board[y][x];
			if (board[y][x] == 'G') {
				nboard[y][x] = 'R';
			}
			else {
				nboard[y][x] = board[y][x];
			}
		}
	}

	int nonRG = 0;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (!visit[y][x]) {
				nonRG++;
				bfs(y, x, board[y][x], board);
			}
		}
	}

	memset(visit, false, sizeof(visit));
	int RG = 0;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (!visit[y][x]) {
				RG++;
				bfs(y, x, nboard[y][x], nboard);
			}
		}
	}

	cout << nonRG << " " << RG << endl;

	return 0;
}
