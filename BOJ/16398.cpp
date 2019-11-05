#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 1000;

int planet[MAX][MAX];
int parent[MAX], ranks[MAX];

int find(int v)
{
  return v == parent[v] ? v : parent[v] = find(parent[v]);
}

void merge(int a, int b)
{
  a = find(a);
  b = find(b);
  if (a != b)
  {
    if (ranks[a] < ranks[b])
      swap(a, b);
    parent[b] = a;
    if (ranks[a] == ranks[b])
      ranks[a]++;
  }
}

struct Edge
{
  int u, v, weight;
  bool operator<(const Edge& e) const
  {
    return weight < e.weight;
  }
};

int main()
{
  int n; scanf("%d", &n);
  for (int y = 0; y < n; ++y)
  {
    for (int x = 0; x < n; ++x)
      scanf("%d", &planet[y][x]);
  }
  vector<Edge> edge;
  for (int y = 0; y < n; ++y)
  {
    for (int x = y + 1; x < n; ++x)
      edge.push_back({ y,x,planet[y][x] });
  }
  sort(edge.begin(), edge.end());
  for (int i = 0; i < n; ++i)
  {
    parent[i] = i;
    ranks[i] = 0;
  }
  ll result = 0;
  for (int i = 0; i < (int)edge.size(); ++i)
  {
    Edge e = edge[i];
    if (find(e.u) != find(e.v))
    {
      result += e.weight;
      merge(e.u, e.v);
    }
  }
  printf("%lld\n", result);
  return 0;
}
