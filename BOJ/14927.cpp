#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 18;

int n;
int bulb[MAX];
int simulation[MAX];

void pressSwitch(int y, int x)
{
  simulation[y] ^= (1 << (n - x - 1));
  if(y)
    simulation[y - 1] ^= (1 << (n - x - 1));
  if (y != n - 1)
    simulation[y + 1] ^= (1 << (n - x - 1));
  if (x)
    simulation[y] ^= (1 << (n - x));
  if (x != n - 1)
    simulation[y] ^= (1 << (n - x - 2));
}

int main()
{
  scanf("%d", &n);
  for (int y = 0; y < n; ++y)
  {
    for (int x = n - 1; x >= 0; --x)
    {
      int temp; scanf("%d", &temp);
      if (temp)
        bulb[y] |= 1 << x;
    }
  }

  int ret = INF;
  for (int candi = (1 << n) - 1; candi >= 0; --candi)
  {
    int press = 0;
    for (int i = 0; i < n; ++i)
      simulation[i] = bulb[i];
    for (int x = 0; x < n; ++x)
    {
      if (candi & (1 << x))
      {
        pressSwitch(0, x);
        press++;
      }
    }
    for (int y = 1; y < n; ++y)
    {
      for (int x = 0; x < n; ++x)
      {
        if (simulation[y - 1] & (1 << (n - x - 1)))
        {
          pressSwitch(y, x);
          press++;
        }
      }
    }
    if (simulation[n - 1] == 0)
    {
      if (ret > press)
        ret = press;
    }
  }
  if (ret == INF)
    printf("-1\n");
  else
    printf("%d\n", ret);
  return 0;
}
