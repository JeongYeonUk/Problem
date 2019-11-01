#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int DEPTH = 63 * 2 + 1;
const int MAX = 63 + 1;

int k, n;
ll cache[DEPTH][MAX];

ll solve(int depth, int time)
{
  if (!depth)
    return 0;
  else if (!time)
    return 1;

  ll& ret = cache[depth][time];
  if (ret != -1)
    return ret;

  return ret = solve(depth + 1, time - 1)
    + solve(depth - 1, time - 1);
}

int main()
{
  scanf("%d %d", &k, &n);
  memset(cache, -1, sizeof(cache));
  printf("%lld\n", solve(k, n));
  return 0;
}
