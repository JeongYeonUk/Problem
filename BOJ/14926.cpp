#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 501;

int n;
int edges[MAX][MAX];
int crossed[MAX][MAX];

void solve()
{
  int curVertex = 0;
  crossed[1][n] = crossed[n][1] = true;
  for (int i = 0; i < (n * (n - 1) / 2); ++i)
  {
    for (int vertex = 1; vertex <= n; ++vertex)
    {
      if (vertex == curVertex || crossed[curVertex][vertex])
      {
        continue;
      }
      crossed[curVertex][vertex] = crossed[vertex][curVertex] = true;
      curVertex = vertex;
      break;
    }
    printf("a%d ", curVertex);
  }
  printf("a1\n");
}

int main()
{
  scanf("%d", &n);
  solve();
  return 0;
}
