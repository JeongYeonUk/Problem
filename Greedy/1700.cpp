#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

int arr[101];
int use[101];
int N, K;

int main()
{
  scanf("%d %d", &N, &K);
  for (int i = 0; i < K; ++i)
  {
    scanf("%d", &arr[i]);
  }

  int ans = 0;
  for (int i = 0; i < K; ++i)
  {
    bool check = false;
    for (int j = 0; j < N; ++j)
    {
      if (arr[i] == use[j])
      {
        check = true;
        break;
      }
    }
    if (check) continue;
    for (int j = 0; j < N; ++j)
    {
      if (use[j] == 0)
      {
        use[j] = arr[i];
        check = true;
        break;
      }
    }
    if (check) continue;

    int idx, val = -1;
    for (int j = 0; j < N; ++j)
    {
      int temp = 0;
      for (int t = i + 1; t < K && use[j] != arr[t]; ++t)
        temp++;
      if (temp > val)
      {
        idx = j;
        val = temp;
      }
    }
    ans++;
    use[idx] = arr[i];
  }
  printf("%d\n", ans);
  return 0;
}
