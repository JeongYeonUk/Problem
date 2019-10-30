#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
int main()
{
  int x;
  map<int, int> m;
  while (scanf("%d", &x))
  {
    if (m.find(x) != m.end())
      continue;
    printf("%d ", x);
    m[x] = 1;
  }
  return 0;
}
