#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x7FFFFFFF;
const int MAX_N = 32003;
const int MAX_M = 100003;

int indegree[MAX_M];
int N, M;
vector<int> adj[MAX_N];

void topologySort()
{
  queue<int> q;
  for (int i = 1; i <= N; ++i)
  {
    if (indegree[i] == 0)
      q.push(i);
  }
  while (!q.empty())
  {
    int cur = q.front(); q.pop();
    for (int i = 0; i < adj[cur].size(); ++i)
    {
      int next = adj[cur][i];
      if (--indegree[next] == 0)
        q.push(next);
    }
    cout << cur << ' ';
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M;
  for (int i = 0; i < M; ++i)
  {
    int A, B;
    cin >> A >> B;
    adj[A].push_back(B);
    adj[B].push_back(A);
    indegree[B]++;
  }

  topologySort();

  return 0;
}
