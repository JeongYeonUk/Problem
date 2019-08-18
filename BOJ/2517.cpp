#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX_N = 500001;

bool cmp(pii a, pii b)
{
  return a.second < b.second;
}

pii arr[MAX_N];
int seg[MAX_N * 4];
int N;

int update(int node, int left, int right, int idx, int val)
{
  if (idx < left || right < idx)
    return seg[node];
  if (left == right)
    return seg[node] = val;
  int mid = (left + right) >> 1;
  return seg[node] = update(node * 2, left, mid, idx, val)
    + update(node * 2 + 1, mid + 1, right, idx, val);
}

int query(int node, int left, int right, int qleft, int qright)
{
  if (qright < left || right < qleft)
    return 0;
  if (qleft <= left && right <= qright)
    return seg[node];
  int mid = (left + right) >> 1;
  return query(node * 2, left, mid, qleft, qright)
    + query(node * 2 + 1, mid + 1, right, qleft, qright);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  sort(arr + 1, arr + 1 + N);

  for (int i = 1; i <= N; ++i)
  {
    arr[i].first = i;
  }

  sort(arr + 1, arr + 1 + N, cmp);

  for (int i = 1; i <= N; ++i)
  {
    cout << 1 + query(1, 1, N, arr[i].first, N) << '\n';
    update(1, 1, N, arr[i].first, 1);
  }

  return 0;
}
