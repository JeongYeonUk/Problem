#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
#define Cost first
#define End second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXV = 20000 + 1;
const int MAXE = 300000 + 1;

vector<pii> adj[MAXV]; // X : cost, Y : end
int dist[MAXV];
int V, E, K;

void solve(int start)
{
	priority_queue<pii, vector<pii>, less<pii>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cur_cost = -pq.top().Cost;
		int cur = pq.top().End;
		pq.pop();
		if (dist[cur] < cur_cost) continue;
		for (int i = 0, size = (int)adj[cur].size(); i < size; ++i)
		{
			int next_cost = cur_cost + adj[cur][i].Cost;
			int next = adj[cur][i].End;

			if (dist[next] > next_cost)
			{
				dist[next] = next_cost;
				pq.push(make_pair(-next_cost, next));
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> V >> E >> K;

	for (int e = 0; e < E; ++e)
	{
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back(make_pair(w, v));
	}

	for (int v = 1; v <= V; ++v)
	{
		dist[v] = INF;
	}
	dist[K] = 0;
	solve(K);

	for (int v = 1; v <= V; ++v)
	{
		if (dist[v] == INF)
			cout << "INF" << endl;
		else
			cout << dist[v] << endl;
	}

	return 0;
}
