#pragma warning (disable :4996)
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[40001];
int d[40001];

int solve()
{
  d[1] = arr[1];
  int idx = 1;
  for (int i = 2; i <= n; ++i)
  {
    if(d[idx] < arr[i])
    {
      d[++idx] = arr[i];
      continue;
    }
    int tempIdx = lower_bound(d + 1, d + idx + 1, arr[i]) - d;
    d[tempIdx] = arr[i];
  }
  return idx;
}

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d", &arr[i]);
  }
  printf("%d\n", solve());

  return 0;
}
