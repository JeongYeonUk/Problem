#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

struct POS {
	int y, x;
};

int N, L, R;
int people, num;
int graph[50][50];
bool visit[50][50];
vector<POS> v;

void dfs(int sy, int sx) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];
		if (ny >= N || nx >= N || ny < 0 || nx < 0) {
			continue;
		}
		int delta = abs(graph[sy][sx] - graph[ny][nx]);
		if (!visit[ny][nx] && L <= delta && delta <= R) {
			visit[ny][nx] = true;
			v.push_back({ ny,nx });
			people += graph[ny][nx];
			num++;
			dfs(ny, nx);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> L >> R;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> graph[y][x];
		}
	}
	int ret = 0;
	while (true) {
		memset(visit, false, sizeof(visit));
		bool found = false;
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				if (visit[y][x]) {
					continue;
				}
				visit[y][x] = true;
				people = graph[y][x];
				num = 1;
				v.clear();
				v.push_back({ y,x });
				dfs(y, x);
				if (num >= 2) {
					found = true;
					for (int i = 0; i < (int)v.size(); ++i) {
						graph[v[i].y][v[i].x] = people / num;
					}
				}
			}
		}
		if (found)
			ret++;
		else
			break;
	}
	cout << ret << '\n';

	return 0;
}
