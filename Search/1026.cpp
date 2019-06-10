#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

int A[50];
int B[50];
int N;
int ans;

void quickLess(int start, int end)
{
  if (start >= end) return;
  int pivot = start;
  int left = start + 1;
  int right = end;
  int temp;
  while (left <= right)
  {
    while (left <= end && A[left] <= A[pivot])
      left++;
    while (right > start && A[right] >= A[pivot])
      right--;
    if (left > right)
    {
      temp = A[right];
      A[right] = A[pivot];
      A[pivot] = temp;
    }
    else
    {
      temp = A[right];
      A[right] = A[left];
      A[left] = temp;
    }
  }

  quickLess(start, right - 1);
  quickLess(right + 1, end);
}

void quickGreater(int start, int end)
{
  if (start >= end) return;
  int pivot = start;
  int left = start + 1;
  int right = end;
  int temp;
  while (left <= right)
  {
    while (left <= end && B[left] >= B[pivot])
      left++;
    while (right > start && B[right] <= B[pivot])
      right--;
    if (left > right)
    {
      temp = B[right];
      B[right] = B[pivot];
      B[pivot] = temp;
    }
    else
    {
      temp = B[right];
      B[right] = B[left];
      B[left] = temp;
    }
  }

  quickGreater(start, right - 1);
  quickGreater(right + 1, end);
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &B[i]);
  }

  quickLess(0, N - 1);
  quickGreater(0, N - 1);

  for (int i = 0; i < N; ++i)
  {
    ans += A[i] * B[i];
  }

  printf("%d\n", ans);

  return 0;
}
