#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/*
1
3 4
1 2 1
3 2 1
1 3 5
2 3 2
*/

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX = 400 + 1;

struct NODE {
	int end;
	int cost;
};

vector<NODE> graph[MAX];
bool used[MAX];
int N, M, ans;

// 시작점, 현재 노드, 누적 코스트
void dfs(int src, int cur, int cost) {
	if (cost != 0 && src == cur) {
		if (cost < ans)
			ans = cost;
		return;
	}

	used[cur] = true;
	for (int i = 0; i < (int)graph[cur].size(); ++i) {
		int next = graph[cur][i].end;
		int nextCost = graph[cur][i].cost;
		if (ans < cost + nextCost)
			continue;
		if (src == next) {
			dfs(src, next, cost + nextCost);
		}
		else {
			if (used[next])
				continue;
			dfs(src, next, cost + nextCost);
		}
	}
	used[cur] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		for (int i = 0; i < MAX; ++i)
			graph[i].clear();
		ans = INF;

		cin >> N >> M;
		for (int i = 0; i < M; ++i) {
			int a, b, c; cin >> a >> b >> c;
			graph[a].push_back({ b,c });
		}

		for (int i = 1; i <= N; ++i) {
			memset(used, false, sizeof(used));
			dfs(i, i, 0);
		}

		cout << "#" << t << " " << ans << endl;
	}

	return 0;
}