#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

char map[8][8];
int color[8][8];
int ans;

int main()
{

  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 8; ++j)
    {
      if (i & 1)
      {
        color[i][j] = (j & 1) + 1;
      }
      else
      {
        color[i][j] = (j & 1);
      }
    }
  }

  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 8; ++j)
    {
      scanf(" %c", &map[i][j]);
      if (map[i][j] == 'F' && color[i][j] != 1)
        ans++;
    }
  }

  printf("%d\n", ans);

  return 0;
}
