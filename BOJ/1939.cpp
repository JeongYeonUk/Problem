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
const int MAX = 100000 + 5;

struct INFO {
	int next, cost;
};

vector<INFO> graph[MAX];
bool visit[MAX];
int start, des, N, M;

bool bfs(int cost) {
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == des)
			return true;
		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i].next;
			int nextCost = graph[cur][i].cost;
			if (visit[next])
				continue;
			if (cost <= nextCost) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> N >> M;

	int maxCost = 0;
	for (int i = 0; i < M; ++i) {
		int A, B, C; cin >> A >> B >> C;
		graph[A].push_back({ B,C });
		graph[B].push_back({ A,C });
		if (maxCost < C) {
			maxCost = C;
		}
	}
	cin >> start >> des;
	int low = 0, high = maxCost;
	while (low <= high) {
		memset(visit, false, sizeof(visit));
		int mid = (low + high) / 2;
		if (bfs(mid)) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << high << endl;

	return 0;
}
