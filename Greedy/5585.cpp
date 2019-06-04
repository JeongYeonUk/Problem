#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

int money[] = { 500,100,50,10,5,1 };

int main()
{
  int n; scanf("%d", &n);
  n = 1000 - n;
  int ans = 0;
  for (int i = 0; i < 6; ++i)
  {
    ans += n / money[i];
    n %= money[i];
  }

  printf("%d\n", ans);

  return 0;
}
