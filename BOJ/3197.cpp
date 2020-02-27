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
const int MAX = 1500 + 5;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct POS {
	int y, x;
};

char lake[MAX][MAX];
bool visit[MAX][MAX];
int N, M;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	vector<POS> swan;
	queue<POS> waterQ;
	cin >> N >> M;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> lake[y][x];
			if (lake[y][x] == 'L') {
				swan.push_back({ y,x });
			}
			if (lake[y][x] == '.' || lake[y][x] == 'L') {
				waterQ.push({ y,x });
			}
		}
	}

	queue<POS> swanQ;
	swanQ.push(swan[0]);
	visit[swan[0].y][swan[0].x] = true;

	int day = 0;
	while (true) {
		queue<POS> nextQ;

		bool flag = false;
		while (!swanQ.empty()) {
			int y = swanQ.front().y; int x = swanQ.front().x;
			swanQ.pop();

			if (y == swan[1].y && x == swan[1].x) {
				flag = true;
				break;
			}

			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx])
					continue;

				visit[ny][nx] = true;

				if (lake[ny][nx] == 'X') {
					nextQ.push({ ny, nx });
					continue;
				}

				swanQ.push({ ny,nx });
			}
		}

		if (flag)
			break;

		swanQ = nextQ;

		int qSize = waterQ.size();
		while (qSize--) {
			int y = waterQ.front().y; int x = waterQ.front().x;
			waterQ.pop();

			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M)
					continue;
				if (lake[ny][nx] == 'X') {
					lake[ny][nx] = '.';
					waterQ.push({ ny,nx });
				}
			}
		}
		day++;
	}

	cout << day << endl;

	return 0;
}
