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
const int MAX = 10 + 5;

bool visit[MAX];
int N, M, ans;

void dfs(int cur, vector<int> graph[MAX], int dist) {
	visit[cur] = true;
	if (ans < dist) {
		ans = dist;
	}
	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		int nextDist = dist + 1;
		if (visit[next])
			continue;
		dfs(next, graph, nextDist);
		visit[next] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> N >> M;
		if (M == 0) {
			cout << '#' << t << " 1\n";
			continue;
		}
		vector<int> graph[MAX];
		for (int i = 0; i < M; ++i) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		ans = 0;
		for (int i = 1; i <= N; ++i) {
			memset(visit, false, sizeof(visit));
			dfs(i, graph, 1);
		}

		cout << '#' << t << ' ' << ans << endl;
	}

	return 0;
}
