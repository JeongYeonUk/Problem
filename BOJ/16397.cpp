#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 100000;

struct INFO
{
  int val, time;
};

int n, t, g;
int visited[MAX];
INFO q[MAX];

int bfs()
{
  int ret = -1;
  int f = 0, r = 0;
  q[r] = { n,0 };
  r = (r + 1) % MAX;
  //queue<INFO> q;
  //q.push({ n,0 });
  visited[n] = true;
  while (f != r)
  {
    //INFO cur = q.front(); q.pop();
    INFO cur = q[f]; f = (f + 1) % MAX;
    if (cur.time > t)
      break;
    if (cur.val == g)
    {
      ret = cur.time;
      break;
    }
    int A = cur.val + 1;
    if (A < MAX && !visited[A])
    {
      q[r] = { cur.val + 1, cur.time + 1 };
      r = (r + 1) % MAX;
      visited[A] = true;
    }
    int B = (cur.val << 1);
    if (B >= MAX)
      continue;
    int digit = 1;
    int temp = B;
    while (temp)
    {
      temp /= 10; digit *= 10;
    }
    digit /= 10;
    B-= digit;
    if (B < MAX && !visited[B])
    {
      q[r] = { B,cur.time + 1 };
      r = (r + 1) % MAX;
      visited[B] = true;
    }
  }
  return ret;
}

int main()
{
  scanf("%d %d %d", &n, &t, &g);
  int ret = bfs();
  if (ret == -1)
    printf("ANG\n");
  else
    printf("%d\n", ret);
  return 0;
}
