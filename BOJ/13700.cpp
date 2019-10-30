#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int MAXN = 100001;
const int INF = 987654321;

struct INFO
{
  int pos, cnt;
};

int police[MAXN];
bool visited[MAXN];
INFO q[MAXN];
int fp, rp;
int n, s, d, f, b, k;

int bfs(int start)
{
  int ret = -1;
  q[fp] = { start,0 };
  visited[start] = true;
  fp = (fp + 1) % MAXN;
  while (fp != rp)
  {
    int cur = q[rp].pos;
    int curCnt = q[rp].cnt;
    rp = (rp + 1) % MAXN;
    if (cur == d)
    {
      ret = curCnt;
      break;
    }
    if (police[cur])
    {
      continue;
    }
    if ((cur + f < MAXN) && !visited[cur + f])
    {
      q[fp].pos = cur + f;
      q[fp].cnt = curCnt+ 1;
      fp = (fp + 1) % MAXN;
      visited[cur + f] = true;
    }
    if ((cur - b > 0) && !visited[cur - b])
    {
      q[fp].pos = cur - b;
      q[fp].cnt = curCnt+1;
      fp = (fp + 1) % MAXN;
      visited[cur - b] = true;
    }
  }

  return ret;
}

int main()
{  
  scanf("%d %d %d %d %d %d", &n, &s, &d, &f, &b, &k);
  for (int i = 0; i < k; ++i)
  {
    int x; scanf("%d", &x);
    police[x] = 1;
  }
  int ret = bfs(s);
  if (ret == -1)
    printf("BUG FOUND\n");
  else
    printf("%d\n", ret);
  return 0;
}
