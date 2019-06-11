#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

typedef struct _node
{
  int pos;
  int cnt;
}NODE;

int n, k;
bool visit[1000001];
NODE q[1000001];
int fp, rp;
void bfs(int from, int to)
{  
  q[fp++] = { from, 0 };
  while (fp != rp)
  {
    int cur = q[rp].pos;
    int cnt = q[rp++].cnt;
    if (cur < 0 || cur > 100000) continue;
    if (visit[cur]) continue;
    visit[cur] = true;
    if (cur == to)
      break;

    if (cur * 2 <= 100000 && !visit[cur * 2])
      q[fp++] = { cur * 2, cnt + 1 };
    if(cur +1 <= 100000 && !visit[cur+1])
      q[fp++] = { cur +1, cnt + 1 };
    if(cur- 1 >= 0 && !visit[cur-1])
      q[fp++] = { cur -1, cnt + 1 };
  }
}

int main()
{
  scanf("%d %d", &n, &k);
  bfs(n, k);
  printf("%d\n", q[rp-1].cnt);

  return 0;
}
