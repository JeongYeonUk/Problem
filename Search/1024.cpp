#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

int main()
{
  int N, L;
  scanf("%d %d", &N, &L);
  int t, x = -1, iter = -1;

  for (int i = L; i <= 100; ++i)
  {
    t = (i - 1) * i / 2;
    if ((N - t) % i == 0 && (N - t) / i >= 0)
    {
      x = (N - t) / i;
      iter = i;
      break;
    }
  }

  if (x == -1) printf("-1\n");
  else
    for (int i = 0; i < iter; ++i)
      printf("%d ", x + i);

  return 0;
}
