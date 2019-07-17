#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x7FFFFFFF;
const int MAX_N = 100003;
const int LGN = 20;

struct Node
{
  int end;
  int wei;
};

int parent[MAX_N][21];
int qmin[MAX_N][21];
int qmax[MAX_N][21];
int depth[MAX_N];
bool visit[MAX_N];
vector<Node> adj[MAX_N];
int N, K;
void dfs(int here, int dep)
{
  visit[here] = true;
  depth[here] = dep;
  int next;
  int nextwei;
  for (int i = 0; i < adj[here].size(); ++i)
  {
    next = adj[here][i].end;
    nextwei = adj[here][i].wei;
    if (visit[next]) continue;
    dfs(next, dep+1);
    parent[next][0] = here;
    qmin[next][0] = nextwei;
    qmax[next][0] = nextwei;
  }
}

void gene()
{
  for (int j = 1; j <= 20; j++)
  {
    for (int i = 1; i <= N; ++i)
    {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
      qmin[i][j] = min(qmin[i][j - 1], qmin[parent[i][j - 1]][j - 1]);
      qmax[i][j] = max(qmax[i][j - 1], qmax[parent[i][j - 1]][j - 1]);
    }
  }
}

pii lca(int a, int b)
{
  int retmax = -INF;
  int retmin = INF;
  if (depth[a] > depth[b])
    swap(a, b);
  for (int i = 20; i >= 0; --i)
  {
    if (depth[b] - depth[a] >= (1 << i))
    {
      retmin = min(retmin, qmin[b][i]);
      retmax = max(retmax, qmax[b][i]);
      b = parent[b][i];
    }
  }
  if (a == b) return { retmin, retmax };
  for (int i = 20; i >= 0; --i)
  {
    if (parent[a][i] != parent[b][i])
    {
      retmin = min(retmin, min(qmin[a][i], qmin[b][i]));
      retmax = max(retmax, max(qmax[a][i], qmax[b][i]));
      a = parent[a][i];
      b = parent[b][i];
    }
  }
  retmin = min(retmin, min(qmin[a][0], qmin[b][0]));
  retmax = max(retmax, max(qmax[a][0], qmax[b][0]));
  return { retmin, retmax };
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N - 1; ++i)
  {
    int A, B, C; cin >> A >> B >> C;
    adj[A].push_back({ B,C });
    adj[B].push_back({ A,C });
  }
  dfs(1, 0);

  gene();

  cin >> K;
  for (int i = 0; i < K; ++i)
  {
    int D, E; cin >> D >> E;
    pii ret = lca(D, E);
    cout << ret.first << ' ' << ret.second << '\n';
  }
  return 0;
}
