#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int cache[31][31];
int bino(int n, int k)
{
  if (n == k || k == 0)
    return 1;
  int& ret = cache[n][k];
  if (ret > 0)
    return ret;
  return ret = bino(n - 1, k - 1) + bino(n - 1, k);
}

int main()
{
  int n, k; scanf("%d %d", &n, &k);
  printf("%d\n", bino(n - 1, k - 1));
  return 0;
}
