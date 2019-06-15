#pragma warning (disable:4996)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _edge
{
  long long start;
  long long end;
  long long cost;
  bool operator < (const _edge& other) const
  {
    return cost < other.cost;
  }
}Edge;

int N;
long long x[1000];
long long y[1000];
long long p[1000];
bool visit[1000];
Edge a[500000];
Edge b[500000];
double E;

inline long long dist(long long x1, long long y1, long long x2, long long y2)
{
  return ((x1 - x2) * (x1 - x2))
    + ((y1 - y2) * (y1 - y2));
}

inline long long Find(long long x)
{
  return x == p[x] ? x : p[x] = Find(p[x]);
}
inline void Union(long long x, long long y)
{
  p[Find(x)] = Find(y);
}

void merge(int low, int mid, int high)
{
  int i = low, j = mid + 1, k = low;
  while (i <= mid && j <= high)
  {
    if (a[i].cost < a[j].cost)
      b[k++] = a[i++];
    else
      b[k++] = a[j++];
  }
  if (i >= mid)
  {
    while (j <= high)
      b[k++] = a[j++];
  }
  if (j >= high)
  {
    while (i <= mid)
      b[k++] = a[i++];
  }
  for (int i = low; i <= high; ++i)
  {
    a[i] = b[i];
  }
}

void mergeSort(int low, int high)
{
  int mid;
  if (low < high)
  {
    mid = (low + high) / 2;
    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    merge(low, mid, high);
  }
}

int main()
{
  freopen("input.txt", "r", stdin);

  int T; scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases)
  {
    for (int i = 0; i < 1000; ++i)
      visit[i] = false;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
      scanf("%lld", &x[i]);
      p[i] = i;
    }
    for (int i = 0; i < N; ++i)
    {
      scanf("%lld", &y[i]);
    }
    scanf("%lf", &E);
    //vector<Edge> a;
    long long cnt = 0;
    for (int i = 0; i < N-1; ++i)
    {
      for (int j = i+1; j < N; ++j)
      {
        if (i == j) continue;
        if (visit[j]) continue;
        a[cnt].start = i;
        a[cnt].end = j;
        a[cnt].cost = dist(x[i], y[i], x[j], y[j]);
        cnt++;
      }
      visit[i] = true;
    }

    mergeSort(0, cnt-1);

    long long ans = 0;
    for (long long i = 0; i < cnt; ++i)
    {
      Edge e = a[i];
      long long x = Find(e.start);
      long long y = Find(e.end);
      if (x != y)
        Union(e.start, e.end), ans += e.cost;
    }
    printf("#%d %.0f\n", cases, ans * E);
  }

  return 0;
}
