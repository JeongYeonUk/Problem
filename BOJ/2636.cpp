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

int map[MAX][MAX];
bool visit[MAX][MAX];
int N, M, pre;

struct INFO {
	int y, x;
};

enum STATE {
	CHEE = 1,
	PREAIR,
	AIR
};

bool allClear() {
	int cnt = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (map[y][x] == CHEE) {
				cnt++;
			}
		}
	}
	if (cnt)
		pre = cnt;
	return cnt ? false : true;
}

void deleteChee() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (map[y][x] == PREAIR) {
				map[y][x] = AIR;
			}
		}
	}
}

void updatePre() {
	memset(visit, false, sizeof(visit));
	queue<INFO> q;
	q.push({ 0,0 });
	visit[0][0] = true;
	while (!q.empty()) {
		INFO cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (visit[ny][nx])
				continue;
			if (map[cur.y][cur.x] == AIR && map[ny][nx] == CHEE) {
				map[ny][nx] = PREAIR;
				visit[ny][nx] = true;
			}
			if (map[ny][nx] == AIR) {
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

void spreadAir() {
	memset(visit, false, sizeof(visit));
	queue<INFO> q;
	q.push({ 0,0 });
	visit[0][0] = true;
	while (!q.empty()) {
		INFO cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (visit[ny][nx])
				continue;
			if (map[ny][nx] == 0 || map[ny][nx] == AIR) {
				map[ny][nx] = AIR;
				visit[ny][nx] = true;
				q.push({ ny,nx });
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
		for (int x = 0; x < M; ++x) {
			cin >> map[y][x];
		}
	}

	int ret = 0;
	while (true) {
		if (allClear()) {
			break;
		}
		spreadAir();
		/*for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				cout << map[y][x] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		updatePre();
		/*for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				cout << map[y][x] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		deleteChee();
		/*for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				cout << map[y][x] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		ret++;
	}
	cout << ret << endl << pre << endl;
	return 0;
}
