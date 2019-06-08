#pragma warning (disable :4996)
#include <cstdio>
#include <algorithm>
using namespace std;

char arr[10];
int n;

bool valid(int* number)
{
  for (int i = 0; i < n; ++i)
  {
    if (arr[i] == '<' && number[i] > number[i + 1])
      return false;
    else if (arr[i] == '>' && number[i] < number[i + 1])
      return false;
  }
  return true;
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf(" %c", &arr[i]);
  }
  int minNumber[] = { 0,1,2,3,4,5,6,7,8,9 };
  int maxNumber[] = { 9,8,7,6,5,4,3,2,1,0 };
  while (1)
  {
    if (valid(minNumber))
      break;
    next_permutation(minNumber, minNumber + 10);
  }
  while (1)
  {
    if (valid(maxNumber))
      break;
    prev_permutation(maxNumber, maxNumber + 10);
  }

  for (int i = 0; i < n + 1; ++i)
  {
    printf("%d", maxNumber[i]);
  }
  printf("\n");
  for (int i = 0; i < n + 1; ++i)
  {
    printf("%d", minNumber[i]);
  }
  printf("\n");

  return 0;
}
