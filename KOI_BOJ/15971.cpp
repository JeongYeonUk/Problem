#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 100001;

struct Node
{
	int end;
	int val;
};

int N, A, B;
vector<Node> vec[MAX];
bool visit[MAX];
int dist[MAX];
int maxi[MAX];
void dfs(int start, int d, int m)
{
	dist[start] = d;
	maxi[start] = m;
	visit[start] = true;
	for (int i = 0; i < (int)vec[start].size(); ++i)
	{
		int next = vec[start][i].end;
		int nextDist = vec[start][i].val;
		if (!visit[next])
		{
			dfs(next, d + nextDist, max(m, nextDist));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> A >> B;
	for (int i = 0; i < N-1; ++i)
	{
		int x, y, z; cin >> x >> y >> z;
		vec[x].push_back({ y,z });
		vec[y].push_back({ x,z });
	}

	if (A == B)
	{
		cout << "0\n";
		return 0;
	}

	dfs(A,0,0);

	cout << dist[B] - maxi[B] << '\n';

	return 0;
}