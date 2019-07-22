#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int LGN = 21;
const int MAX_N = 100003;
const int MAX_M = 100003;

int parent[MAX_N][LGN+1];
bool visit[MAX_N];
int depth[MAX_N];
vector<int> adj[MAX_N];
int N, M;

void dfs(int here)
{
  visit[here] = true;
  int next;
  for (int i = 0; i < adj[here].size(); ++i)
  {
    next = adj[here][i];
    if (visit[next]) continue;
    depth[next] = depth[here] + 1;
    parent[next][0] = here;
    dfs(next);
  }
}

void makeParent()
{
  for (int j = 1; j < LGN; ++j)
  {
    for (int i = 1; i <= N; ++i)
    {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
  }
}

int lca(int a, int b)
{
  if (depth[a] > depth[b])
    swap(a, b);
  for (int i = LGN - 1; i >= 0; --i)
  {
    if (depth[b] - depth[a] >= (1 << i))
    {
      b = parent[b][i];
    }
  }

  if (a == b) return a;

  for (int i = LGN - 1; i >= 0; --i)
  {
    if (parent[a][i] != parent[b][i])
    {
      a = parent[a][i];
      b = parent[b][i];
    }
  }

  return parent[a][0];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N - 1; ++i)
  {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  depth[1] = 0;
  dfs(1);

  makeParent();

  cin >> M;
  for (int i = 0; i < M; ++i)
  {
    int a, b; cin >> a >> b;
    cout << lca(a, b) << '\n';
  }
  return 0;
}
