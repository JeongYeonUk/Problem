#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

int main()
{
  freopen("input.txt", "r", stdin);

  int T; scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases)
  {
    long long N;
    scanf("%lld", &N);
    if (N <= 3)
    {
      if (N == 1)
      {
        printf("#%d Bob\n", cases);
      }
      else
      {
        printf("#%d Alice\n", cases);
      }
    }
    else
    {
      long long size = 4LL;
      int w = 2;
      while (true)
      {
        if (N >= size && N < (size << 1))
          break;
        size = size << 1;
        w++;
      }
      long long x = 1LL;
      if (w % 2)
      {
        for (int i = 1; i <= w; ++i)
        {
          if (i % 2) x = x << 1;
          else x = (x << 1) + 1;
        }
        if (x <= N)
          printf("#%d Alice\n", cases);
        else
          printf("#%d Bob\n", cases);
      }
      else
      {
        for (int i = 1; i <= w; ++i)
        {
          if (i % 2) x = (x << 1) + 1;
          else x = x << 1;
        }
        if (x > N)
          printf("#%d Alice\n", cases);
        else
          printf("#%d Bob\n", cases);
      }
    }
  }
  return 0;
}
