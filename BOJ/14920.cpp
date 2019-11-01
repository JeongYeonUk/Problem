#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
  int n; scanf("%d", &n);
  int cnt = 1;
  while (n != 1)
  {
    if (n & 1)
    {
      n = 3 * n + 1;
    }
    else
    {
      n /= 2;
    }
    cnt++;
  }

  printf("%d\n", cnt);
  return 0;
}
