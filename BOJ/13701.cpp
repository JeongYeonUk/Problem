#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int arr[(1 << 25) / 32];
int main()
{
  int n;
  while (~scanf("%d", &n))
  {
    int x = n / 32;
    int y = 1 << (n % 32);
    if (!(arr[x] & y))
    {
      printf("%d ", n);
      arr[x] |= y;
    }
  }
  return 0;
}
