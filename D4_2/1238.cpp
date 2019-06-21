#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

#define MAX 111*111

typedef struct _node
{
  int val;
  int level;
}Node;

int arr[111][111];
bool visit[111];
Node q[MAX];
int fp, rp;
int Answer;

void solve(int start)
{
  visit[start] = true;
  q[fp++].val = start;
  while (fp != rp)
  {
    int cur = q[rp].val;
    int cur_level = q[rp++].level;
    for (int i = 1; i < 111; ++i)
    {
      if (arr[cur][i] == 1 && !visit[i])
      {
        visit[i] = true;
        q[fp].val = i;
        q[fp++].level = cur_level + 1;
      }
    }
  }

  int final_level = q[rp - 1].level;
  int cnt = 0;
  for (int i = rp - 1; i >= 0; --i)
  {
    if (q[i].level == final_level)
      cnt++;
    else
      break;
  }
  for (int i = 1; i <= cnt; ++i)
  {
    if (Answer < q[rp - i].val)
      Answer = q[rp - i].val;
  }
}

int main()
{
  freopen("input.txt", "r", stdin);

  //int T; scanf("%d", &T);
  for (int cases = 1; cases <= 10; ++cases)
  {
    fp = rp = Answer = 0;
    for (int i = 0; i < 111; ++i)
    {
      visit[i] = false;
      q[i].val = q[i].level = 0;
    }
    for (int i = 0; i < 111; ++i)
    {
      for (int j = 0; j < 111; ++j)
      {
        arr[i][j] = 0;
      }
    }
    int N, start; scanf("%d %d", &N, &start);
    for (int i = 0; i < N; i += 2)
    {
      int from, to; scanf("%d %d", &from, &to);
      arr[from][to] = 1;
    }
    solve(start);
    printf("#%d %d\n", cases, Answer);
  }

  return 0;
}
