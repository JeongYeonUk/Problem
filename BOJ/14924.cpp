#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
  int s, t, d; scanf("%d %d %d", &s, &t, &d);
  int meet = d / (s << 1);
  printf("%d\n", meet * t);
  return 0;
}
