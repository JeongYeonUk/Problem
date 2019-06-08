#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

int arr[11], tmp, n;

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d", &tmp);
    int j = 1, cnt = 0;
    while (true)
    {
      if (arr[j])
      {
        j++;
        continue;
      }
      if (cnt == tmp)
      {
        arr[j] = i;
        break;
      }
      j++, cnt++;
    }
  }
  for (int i = 1; i <= n; ++i)
    printf("%d ", arr[i]);

  return 0;
}
