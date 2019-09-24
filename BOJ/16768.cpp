#pragma warning(disable : 4996)
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

struct INFO {
	int y, x;
	INFO(int y = 0, int x = 0) : y(y), x(x){}
};

int map[100][10];
bool visited[100][10];
int n, k;
bool flag;

// remove function
void boom(int sy, int sx) {
	int tmp[100][10] = { 0, };
	bool visit[100][10] = { 0, };
	// copy
	for (int y = 0; y < 100; ++y) {
		for (int x = 0; x < 10; ++x) {
			tmp[y][x] = map[y][x];
		}
	}
	queue<INFO> q;
	q.push({ sy,sx });
	visit[sy][sx] = 1;
	while (!q.empty()) {
		INFO cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			INFO next;
			next.y = cur.y + dy[dir];
			next.x = cur.x + dx[dir];
			if (next.x < 0 || next.y < 0 || next.x >= 10 || next.y >= 6) {
				continue;
			}
			if (!visit[next.y][next.x] &&tmp[cur.y][cur.x] == tmp[next.y][next.x]) {				
				visit[next.y][next.x] = 1;
				q.push({ next.y,next.x });
			}
		}
		tmp[cur.y][cur.x] = 0; // remove
	}
	// re-copy
	for (int y = 0; y < 100; ++y) {
		for (int x = 0; x < 10; ++x) {
			map[y][x] = tmp[y][x];
		}
	}
}

// serach cells
void bfs(int sy, int sx) {
	visited[sy][sx] = 1;
	queue<INFO> q;
	q.push({ sy,sx });
	int cnt = 1;
	while (!q.empty()) {
		if (cnt >= k) {
			flag = false;
			boom(sy, sx);
			break;
		}
		INFO cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			INFO next;
			next.y = cur.y + dy[dir];
			next.x = cur.x + dx[dir];
			if (next.x < 0 || next.y < 0 || next.x >= 10 || next.y >= 6) {
				continue;
			}
			if (!visited[next.y][next.x] && map[cur.y][cur.x] == map[next.y][next.x]) {
				visited[next.y][next.x] = 1;
				q.push({ next.y,next.x });
				cnt++;
			}
		}
	}
}

// gravity
void down(int sy, int sx) {
	while (true) {
		if (sy == n-1) break;
		if (map[sy + 1][sx] != 0) break;
		swap(map[sy][sx], map[sy + 1][sx]);
		sy = sy + 1;
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < 10; ++x) {
			scanf("%1d", &map[y][x]);
		}
	}

	while (true) {
		flag = true;
		memset(visited, false, sizeof(visited));
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < 10; ++x) {
				if (map[y][x] != 0 && !visited[y][x]) {
					visited[y][x] = true;
					bfs(y,x);
				}
			}
		}
		if (flag) break;
		for (int y = n-2; y >= 0; --y) {
			for (int x = 0; x < 10; ++x) {
				if (map[y + 1][x] == 0) {
					down(y, x);
				}
			}
		}
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < 10; ++x) {
			printf("%d",map[y][x]);
		}
		printf("\n");
	}


	return 0;
}
