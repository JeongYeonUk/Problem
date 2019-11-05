#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 2000001;
int arr[MAX];

int main()
{
  for (int i = 2; i < MAX; ++i)
    arr[i] = i;
  arr[0] = arr[1] = 0;
  for (int i = 2; i < MAX; ++i)
  {
    if (!arr[i]) continue;
    for (int j = i +i; j < MAX; j += i)
    {
      arr[j] = 0;
    }
  }

  long long ret = 0;
  for (long long i = 2; i < MAX; ++i)
  {
    if (arr[i])
      ret += i;
  }
  printf("%lld", ret);
  return 0;
}
