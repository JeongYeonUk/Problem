#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
int line[10010];
int main()
{
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    int a, b; scanf("%d %d", &a, &b);
    for (int j = a; j < b; ++j)
    {
      if (!line[j])
        line[j]++;
    }
  }
  int ret = 0;
  for (int i = 0; i < 10010; ++i)
  {
    if (line[i])
      ret++;
  }
  printf("%d\n", ret);
  return 0;
}
