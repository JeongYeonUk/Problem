#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

int arr[100];
bool d[10001];

int main()
{
  freopen("input.txt", "r", stdin);

  int T; scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases)
  {
    for (int i = 0; i < 10001; ++i)
      d[i] = false;
    int N; scanf("%d", &N);
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
      scanf("%d", &arr[i]);
      sum += arr[i];
    }
    d[0] = true;
    for (int i = 0; i < N; ++i)
    {
      for (int j = sum; j >= 0; --j)
      {
        if (d[j])
        {
          d[j + arr[i]] = true;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < 10001; ++i)
    {
      if (d[i]) ans++;
    }
    printf("#%d %d\n", cases, ans);
  }

  return 0;
}
