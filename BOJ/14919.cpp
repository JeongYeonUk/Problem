#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 1000;

int range[MAX];
int result[MAX];
int m;

int main()
{
  scanf("%d", &m);
  double crit = (double)1 / m + 0.0000000001;

  for (int i = 0; i < m; ++i)
  {
    range[i] = (i + 1) * crit * 1000000;
    if (((i + 1) * 1000000) % m)
      range[i]++;
  }

  double num;
  do
  {
    scanf("%lf", &num);
    num += 0.0000000001;
    num *= 1000000;

    if (0 <= num && num < range[0])
      result[0]++;
    else
    {
      for (int i = 1; i < m; ++i)
      {
        if (range[i - 1] <= num && num < range[i])
        {
          result[i]++;
          break;
        }
      }
    }
  } while (~scanf("%lf", &num));

  for (int i = 0; i < m; ++i)
    printf("%d ", result[i]);
  printf("\n");

  return 0;
}
