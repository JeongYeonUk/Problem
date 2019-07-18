#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x7FFFFFFF;
const int MAX_V = 100003;
const int MAX_E = 1000003;

int found[MAX_V];
vector<pii> cut;
vector<int> adj[MAX_V];
int V, E;
int counter;
int dfs(int here, int parent)
{
  found[here] = ++counter;
  int low = found[here];
  int next, child = 0;
  for (int i = 0; i < (int)adj[here].size(); ++i)
  {
    next = adj[here][i];
    if (next == parent)
      continue;
    if (!found[next])
    {
      int sub = dfs(next, here);
      if (sub > found[here])
      {
        cut.push_back({ min(here,next), max(here, next) });
      }
      if (sub < low)
      {
        low = sub;
      }
    }
    else
    {
      if (found[next] < low)
        low = found[next];
    }
  }
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
  for (int i = 1; i <= V; ++i)
  {
    dfs(i, 1);
  }
  cout << cut.size() << '\n';
  sort(cut.begin(), cut.end());
  for (int i = 0; i < (int)cut.size(); ++i)
  {
    cout << cut[i].first << ' ' << cut[i].second << '\n';
  }
  return 0;
}
