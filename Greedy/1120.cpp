#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

char a[51];
char b[51];
int main()
{
  scanf("%s %s", a, b);
  int a_len = 0, b_len = 0;
  for (int i = 0; a[i] != 0; ++i)
  {
    a_len++;
  }
  for (int i = 0; b[i] != 0; ++i)
  {
    b_len++;
  }
  int cnt = 0;
  int ans = 987654321;
  for (int i = 0; i <= b_len - a_len; ++i)
  {
    cnt = 0;
    for (int j = 0; j < a_len; ++j)
    {
      if (a[j] != b[j + i]) cnt++;
    }
    if (ans > cnt)
      ans = cnt;
  }
  printf("%d\n", ans);

  return 0;
}
