#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
  int ret = 0;
  for (int a = 1; a < 500; ++a)
  {
    for (int b = a+1; b < 500; ++b)
    {
      for (int c = b+1; c < 500; ++c)
      {
        if ((a * a) + (b * b) == (c * c))
        {
          if (a + b + c == 1000)
          {
            ret = a * b * c;
            break;
          }
        }
      }
    }
  }
  printf("%d\n", ret);

  return 0;
}
