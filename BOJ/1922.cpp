#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 1003;
const int MAX_M = 100003;

struct Node
{
  int node[2];
  int distance;
};

int parent[MAX_N];
vector<Node> adj;
int N, M;
int getParent(int x)
{
  if (x == parent[x])
    return x;
  else
    return parent[x] = getParent(parent[x]);
}

void Union(int a, int b)
{
  int ta = a; int tb = b;
  a = getParent(ta); b = getParent(tb);
  if (a > b)
  {
    parent[a] = b;
  }
  else
  {
    parent[b] = a;
  }  
}

bool Find(int a, int b)
{
  a = getParent(a); b = getParent(b);
  if (a != b)
    return 1;
  else
    return 0;
}

bool compare(Node& a, Node& b)
{
  return a.distance < b.distance;
}

Node nd;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M;
  for (int i = 0; i < M; ++i)
  {
    int a, b, c; cin >> a >> b >> c;
    nd.node[0] = a;
    nd.node[1] = b;
    nd.distance = c;
    adj.push_back(nd);
  }

  for (int i = 1; i <= N; ++i)
    parent[i] = i;
  sort(adj.begin(), adj.end(), compare);

  int sum = 0;
  for (int i = 0; i < (int)adj.size(); ++i)
  {
    if (Find(adj[i].node[0], adj[i].node[1]))
    {
      sum += adj[i].distance;
      Union(adj[i].node[0], adj[i].node[1]);
    }
  }

  cout << sum << '\n';

  return 0;
}
