#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX = 400 + 1;

int graph[MAX][MAX];
bool visit[MAX];
int N, M, ans;

// 현재 서있는 정점, 출발지 정점 어디였는지
void dfs(int now, int start, int dist) {
	if (now == start && visit[now]) {
		if (dist < ans)
			ans = dist;
		return;
	}
	if (visit[now] || dist >= ans) {
		return;
	}

	visit[now] = true;
	for (int i = 1; i <= N; ++i) {
		if (graph[now][i] > 0) {
			dfs(i, start, dist + graph[now][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		memset(graph, 0, sizeof(graph));
		memset(visit, false, sizeof(visit));
		ans = INF;
		cin >> N >> M;
		for (int m = 0; m < M; ++m) {
			int s, e, c; cin >> s >> e >> c;
			graph[s][e] = c;
		}

		for (int now = 1; now <= N; ++now) {
			memset(visit, false, sizeof(visit));
			dfs(now, now, 0);
		}

		cout << "#" << t << " " << (ans == INF ? -1 : ans) << endl;
	}

	return 0;
}