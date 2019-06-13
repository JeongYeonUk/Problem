#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

int K;
int arr[13];
int lotto[6];

void makeLotto(int idx1, int idx2)
{
  if (idx2 == 6)
  {
    for (int i = 0; i < 6; ++i)
      printf("%d ", lotto[i]);
    printf("\n");
    return;
  }
  for (int i = idx1; i < K; ++i)
  {
    lotto[idx2] = arr[i];
    makeLotto(i + 1, idx2 + 1);
  }
}

int main()
{
  while (true)
  {
    scanf("%d", &K);
    if (K == 0) break;
    for (int i = 0; i < K; ++i)
    {
      scanf("%d", &arr[i]);
    }
    makeLotto(0, 0);
    printf("\n");
  }

  return 0;
}
