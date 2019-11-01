#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int bottle[10001];
int n, k, m;

bool check(int amount)
{
  int cnt = 0;
  for (int i = 0; i < n; ++i)
  {
    cnt += bottle[i] / amount;
    if (cnt >= k)
      return true;
  }
  return false;
}

int bs()
{
  int low = 1, high = m;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (check(mid))
      low = mid + 1;
    else
      high = mid - 1;
  }
  return high;
}

int main()
{
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &bottle[i]);
    if (m < bottle[i])
      m = bottle[i];
  }

  printf("%d\n", bs());

  return 0;
}
