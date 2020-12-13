#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define endl '\n'
#define INF 987654321

struct State {
	int y, x, gas;
};

const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1, 0, 0 };

bool operator <(State a, State b)
{
	if (a.gas < b.gas) return true;

	if (a.gas == b.gas) {
		if (a.y > b.y) return true;
		if (a.y == b.y) {
			if (a.x > b.x) return true;
		}
	}
	return false;
}

int N, M, gas;
int grid[21][21];
map<pair<int, int>, pair<int, int>> start2Dest;

bool func(pair<int, int> start)
{
	pair<int, int> dest = start2Dest[start];

	queue<pair<State, int>> q;
	q.push({ {start.first, start.second, gas}, 0 });

	bool visited[21][21] = { false, };
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		int y = q.front().first.y;
		int x = q.front().first.x;
		int curGas = q.front().first.gas;
		int cnt = q.front().second;
		q.pop();

		if (curGas == -1) return false;
		if (y == dest.first && x == dest.second) {
			gas = curGas + cnt * 2;
			return true;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

			if (visited[ny][nx] || grid[ny][nx]) continue;

			visited[ny][nx] = true;

			q.push({ {ny, nx, curGas - 1}, cnt + 1 });
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M >> gas;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> grid[i][j];
		}
	}

	pair<int, int> start;
	cin >> start.first >> start.second;
	start.first--; start.second--;

	for (int i = 0; i < M; ++i) {
		int y, x, y2, x2;
		cin >> y >> x >> y2 >> x2;
		start2Dest[{y - 1, x - 1}] = { y2 - 1, x2 - 1 };
	}

	while (true) {
		priority_queue<State> pq;
		pq.push({ start.first, start.second, gas });

		bool visited[21][21] = { false, };
		visited[start.first][start.second] = true;

		bool flag = false;
		
		while (!pq.empty()) {
			int y = pq.top().y;
			int x = pq.top().x;
			int curGas = pq.top().gas;
			pq.pop();

			if (curGas == -1) break;

			// 손님 -> 목적지 인 경우
			if (start2Dest.count({ y, x }) && start2Dest[{y, x}].first != -1) {
				start = { y,x };
				flag = true;
				gas = curGas;
				break;
			}

			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

				if (visited[ny][nx] || grid[ny][nx]) continue;

				visited[ny][nx] = true;

				pq.push({ ny, nx, curGas - 1 });
			}
		}

		// 손님이 없을 경우
		if (flag == false) {
			cout << -1 << endl;
			return 0;
		}

		// 목적지로 못갈 때
		if (func(start) == false) {
			cout << -1 << endl;
			return 0;
		}

		if (--M == 0) {
			cout << gas << endl;
			return 0;
		}

		pair<int, int> tmp = start;
		start = start2Dest[{start.first, start.second}];
		start2Dest[{tmp.first, tmp.second}] = { -1, -1 };
	}

	return 0;
}
