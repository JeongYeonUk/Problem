#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

int N;
int ans;
int tree[51][51];
int visit[51][51];
int root[51];
int q[10001];
int h, t;

void bfs()
{
  while (h != t)
  {
    int cur = q[h++];
    int flag = 0;
    for (int i = 0; i < N; ++i)
    {
      if (tree[cur][i] == 1 && visit[cur][i] == 0)
      {
        flag = 1;
        visit[cur][i] = 1;
        q[t++] = i;
      }
    }
    if (!flag && !root[cur])
      ans++;
  }
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; ++i)
  {
    int in; scanf("%d", &in);
    if (in == -1)
    {
      q[t++] = i;
      root[i] = 1;
      continue;
    }
    tree[in][i] = 1;
  }
  int del; scanf("%d", &del);
  for (int i = 0; i < N; ++i)
  {
    tree[del][i] = tree[i][del] = 0;
  }
  bfs();
  printf("%d\n", ans);
  return 0;
}
