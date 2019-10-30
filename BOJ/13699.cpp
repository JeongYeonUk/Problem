#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

long long cache[36];

int main()
{
  int n; scanf("%d", &n);
  cache[0] = cache[1] = 1;
  cache[2] = 2;
  cache[3] = 5;

  for (int i = 4; i <= n; ++i)
  {
    for (int j = 0, k = i - 1;
      (j < n) && (k >= 0); j++, k--)
    {
      cache[i] += cache[j] * cache[k];
    }
  }
  printf("%lld\n", cache[n]);
  return 0;
}
