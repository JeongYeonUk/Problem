#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

int arr[1001];
int N;

void quickSort(int start, int end)
{
  if (start >= end) return;
  int pivot = start;
  int left = start + 1;
  int right = end;
  int temp;
  while (left <= right)
  {
    while (left <= end && arr[left] <= arr[pivot])
      left++;
    while (right > start && arr[right] >= arr[pivot])
      right--;
    if (left > right)
    {
      temp = arr[right];
      arr[right] = arr[pivot];
      arr[pivot] = temp;
    }
    else
    {
      temp = arr[left];
      arr[left] = arr[right];
      arr[right] = temp;
    }
  }
  quickSort(start, right - 1);
  quickSort(right + 1, end);
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &arr[i]);
  }
  quickSort(0, N - 1);

  if (arr[0] != 1)
    printf("1\n");
  else
  {
    int sum = 1;
    for (int i = 1; i < N; ++i)
    {
      if (arr[i] > sum + 1)
        break;
      sum += arr[i];
    }
    printf("%d\n", sum + 1);
  }

  return 0;
}
