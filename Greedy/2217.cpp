#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

int arr[100000];

void quickSort(int start, int end)
{
  if (start >= end) return;

  int pivot = start;
  int left = start + 1;
  int right = end;

  while (left <= right)
  {
    while (left <= end && arr[left] <= arr[pivot])
      left++;
    while (right > start && arr[right] >= arr[pivot])
      right--;
    if (left > right)
    {
      int temp = arr[right];
      arr[right] = arr[pivot];
      arr[pivot] = temp;
    }
    else
    {
      int temp = arr[left];
      arr[left] = arr[right];
      arr[right] = temp;
    }
  }
  quickSort(start, right - 1);
  quickSort(right + 1, end);
}

int main()
{
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &arr[i]);
  }
  quickSort(0, n-1);

  int ans = arr[n-1];
  int count = 2;
  for (int i = n - 2; i >= 0; --i)
  {
    int temp = arr[i] * count++;
    if (ans < temp)
      ans = temp;
  }

  printf("%d\n", ans);

  return 0;
}
