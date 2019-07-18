#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x7FFFFFFF;
const int MAX_V = 10003;

int V, E, cut[MAX_V], found[MAX_V];
int counter;
vector<int> adj[MAX_V];

int dfs(int here, int is_root)
{
  found[here] = ++counter;
  int low = found[here];
  int next, child = 0;
  for (int i = 0; i < (int)adj[here].size(); ++i)
  {
    next = adj[here][i];
    if (!found[next])
    {
      child++;
      int sub = dfs(next, 0);
      if (!is_root && sub >= found[here])
      {
        cut[here] = true;
      }
      if (sub < low)
      {
        low = sub;
      }
    }
    else
    {
      if (found[next] < low)
      {
        low = found[next];
      }
    }
  }
  if (is_root && child >= 2) cut[here] = true;
  return low;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> V >> E;
  for (int i = 0; i < E; ++i)
  {
    int A, B; cin >> A >> B;
    adj[A].push_back(B);
    adj[B].push_back(A);
  }
  int ans = 0;
  for (int i = 1; i <= V; ++i)
  {
    if (!found[i])
      dfs(i, 1);
  }
  cout << ans << '\n';
  for (int i = 1; i <= V; ++i)
  {
    if (cut[i])
      cout << i << ' ';
  }

  return 0;
}
