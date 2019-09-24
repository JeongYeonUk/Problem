#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

struct INFO {
	int y, x;
};

int r, c;
INFO start, dest;
queue<INFO> river;
char map[50][50];
int cache[50][50];

int bfs() {
	queue<INFO> mole;
	mole.push(start);
	cache[start.y][start.x] = 1;

	int riverSize, moleSize;
	while (!mole.empty()) {
		riverSize = (int)river.size();
		for (int i = 0; i < riverSize; ++i) {
			INFO cur = river.front(); river.pop();
			for (int dir = 0; dir < 4; ++dir) {
				INFO next;
				next.y = cur.y + dy[dir];
				next.x = cur.x + dx[dir];
				if (next.y < 0 || next.x < 0 || next.x >= c || next.y >= r) {
					continue;
				}
				if (map[next.y][next.x] == '.') {
					map[next.y][next.x] = '*';
					river.push({ next.y, next.x });
				}
			}
		}
		moleSize = mole.size();
		for (int i = 0; i < moleSize; ++i) {
			INFO cur = mole.front(); mole.pop();
			if (map[cur.y][cur.x] == 'D') {
				return cache[cur.y][cur.x] - 1;
			}
			for (int dir = 0; dir < 4; ++dir) {
				INFO next;
				next.y = cur.y + dy[dir];
				next.x = cur.x + dx[dir];
				if (next.y < 0 || next.x < 0 || next.x >= c || next.y >= r) {
					continue;
				}
				if (map[next.y][next.x] == '*' || map[next.y][next.x] == 'X') {
					continue;
				}
				if (cache[next.y][next.x] == 0) {
					cache[next.y][next.x] = cache[cur.y][cur.x] + 1;
					mole.push({ next.y, next.x });
				}
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> r >> c;
	for (int y = 0; y < r; ++y) {
		for (int x = 0; x < c; ++x) {
			cin >> map[y][x];
			if (map[y][x] == 'S') {
				start = { y,x };
			}
			else if (map[y][x] == '*') {
				river.push({ y,x });
			}
			else if (map[y][x] == 'D') {
				dest = { y,x };
			}
		}
	}

	int ret = bfs();
	if (ret == -1) {
		cout << "KAKTUS" << endl;
	}
	else {
		cout << ret << endl;
	}

	return 0;
}
