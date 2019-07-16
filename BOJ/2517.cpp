#pragma warning (disable : 4996)
#include <cstdio>
using namespace std;

const int MAX_N = 500003;
int N;
int a[MAX_N][3];  // 0 : val, 1 : idx, 2 : th
int t[MAX_N * 4];

void quicksort(int lb, int rb)
{
  int l = lb, r = rb, tmp;
  int p = a[(l + r) >> 1][0];
  do {
    while (a[l][0] > p) ++l;
    while (p > a[r][0]) --r;
    if (l <= r)
    {
      tmp = a[l][0]; a[l][0] = a[r][0]; a[r][0] = tmp;
      tmp = a[l][1]; a[l][1] = a[r][1]; a[r][1] = tmp;
      tmp = a[l][2]; a[l][2] = a[r][2]; a[r][2] = tmp;
      ++l; --r;
    }
  } while (l <= r);
  if (l < rb) quicksort(l, rb);
  if (lb < r) quicksort(lb, r);
}

void quicksort2(int lb, int rb)
{
  int l = lb, r = rb, tmp;
  int p = a[(l + r) >> 1][1];
  do {
    while (a[l][1] < p) ++l;
    while (p < a[r][1]) --r;
    if (l <= r)
    {
      tmp = a[l][0]; a[l][0] = a[r][0]; a[r][0] = tmp;
      tmp = a[l][1]; a[l][1] = a[r][1]; a[r][1] = tmp;
      tmp = a[l][2]; a[l][2] = a[r][2]; a[r][2] = tmp;
      ++l; --r;
    }
  } while (l <= r);
  if (l < rb) quicksort2(l, rb);
  if (lb < r) quicksort2(lb, r);
}

int queryTree(int node, int left, int right, int qleft, int qright)
{
  if (qright < left || right < qleft) return 0;
  if (qleft <= left && right <= qright) return t[node];
  int mid = (left + right) >> 1;
  return queryTree(node << 1, left, mid, qleft, qright) +
    queryTree((node << 1) + 1, mid + 1, right, qleft, qright);
}

void updateTree(int node, int left, int right, int idx)
{
  if (left == right)
  {
    if (left == idx)
      t[node] = 1;
    return;
  }
  if (idx < left || right < idx) return;

  int mid = (left + right) >> 1;
  updateTree(node << 1, left, mid, idx);
  updateTree((node << 1) + 1, mid + 1, right, idx);
  t[node] = t[node << 1] + t[(node << 1) + 1];
}

int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
  {
    scanf("%d", &a[i][0]);
    a[i][1] = i;
  }

  quicksort(1, N);

  for (int i = 1; i <= N; ++i)
    a[i][2] = i;

  quicksort2(1, N);

  for (int i = 1; i <= N; ++i)
  {
    updateTree(1, 1, N, a[i][2]);
    printf("%d\n", queryTree(1, 1, N, 1, a[i][2]));
  }

  return 0;
}
