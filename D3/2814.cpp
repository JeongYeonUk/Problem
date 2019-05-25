#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 11;

bool visit[MAX];
int N, M;
int maxDist;
void dfs(int start, vector<int> a[MAX], int dist)
{
	visit[start] = true;
	if (maxDist < dist)
		maxDist = dist;
	for (int i = 0; i < a[start].size(); ++i)
	{
		int next = a[start][i];
		int nextDist = dist + 1;
		if (!visit[next])
		{
			dfs(next, a, nextDist);
			visit[next] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		cin >> N >> M;
		vector<int> a[MAX];
		int ret = 0;
		maxDist = 0;
		for (int i = 0; i < M; ++i)
		{
			int x, y; cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for (int i = 1; i <= N; ++i)
		{
			fill(visit, visit + MAX, 0);
			dfs(i, a, 1);
			if (ret < maxDist)
				ret = maxDist;
		}
		cout << '#' << cases << ' ' << ret << '\n';
	}

	return 0;
}