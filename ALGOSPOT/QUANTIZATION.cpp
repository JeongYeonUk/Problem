#include <iostream>
#include <cstring>
using namespace std;

const int INF = 987654321;
int arr[100];
int temp[100];
int pSum[100];
int pSqSum[100];
int cache[100][10];
int N;

inline int MAX(int a, int b)
{
  return a > b ? a : b;
}

inline int MIN(int a, int b)
{
  return a > b ? b : a;
}

void merge(int start, int mid, int end)
{
  int i = start, j = mid+1, k = start;
  while (i <= mid && j <= end)
  {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }
  while(i <= mid)
  {
    temp[k++] = arr[i++];
  }
  while (j <= end)
  {
    temp[k++] = arr[j++];
  }
  for (int i = start; i <= end; ++i)
  {
    arr[i] = temp[i];
  }
}

void mergeSort(int start, int end)
{
  if (start < end)
  {
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, mid, end);
  }
}

void preCal()
{
  mergeSort(0, N - 1);

  pSum[0] = arr[0];
  pSqSum[0] = arr[0] * arr[0];

  for (int i = 1; i < N; ++i)
  {
    pSum[i] = pSum[i - 1] + arr[i];
    pSqSum[i] = pSqSum[i - 1] + (arr[i] * arr[i]);
  }
}

int minDiff(int lo, int hi)
{
  int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
  int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
  int m = int(0.5 + (double)sum / (hi - lo + 1));
  int ret = sqSum - (2 * m * sum) + (m * m * (hi - lo + 1));
  return ret;
}

int quantize(int from, int parts)
{
  if (from == N) return 0;
  if (parts == 0) return INF;
  int& ret = cache[from][parts];
  if (ret != -1) return ret;
  ret = INF;
  for (int i = 1; from + i <= N; ++i)
  {
    ret = MIN(ret, minDiff(from, from + i -1) + quantize(from + i, parts - 1));
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int T; cin >> T;
  for (int cases = 0; cases < T; ++cases)
  {
    int num; cin >> N >> num;
    for (int i = 0; i < N; ++i)
    {
      cin >> arr[i];
    }
    preCal();
    memset(cache, -1, sizeof(cache));
    cout << quantize(0, num) << '\n';
  }

  return 0;
}
