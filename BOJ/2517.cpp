#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x7FFFFFFF;
const int MAX_N = 500003;

pii arr[MAX_N];
int tree[MAX_N];
int N;

bool cmp(pii a, pii b)
{
  return a.second < b.second;
}

int update(int node, int left, int right, int value)
{
  if (value < left || right < value)
    return tree[node];
  else if (left == right)
    return tree[node] = 1;
  return tree[node] = update(node * 2, left, (left + right) >> 1,value)
    + update(node * 2 + 1, ((left + right) >> 1) + 1, right, value);
}

int query(int node, int left, int right, int value)
{
  if (value < left)
    return tree[node];
  else if (right < value || left == right)
    return 0;
  return query(node * 2, left, (left + right) / 2, value)
    + query(node * 2 + 1, (left + right) / 2 + 1, right, value);
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
  sort(arr, arr + N);
  for (int i = 1; i <= N; ++i)
  {
    arr[i].first = i;
  }
  sort(arr, arr + N, cmp);

  for (int i = 1; i <= N; ++i)
  {
    cout << 1 + query(1, 1, N, arr[i].first) << '\n';
    update(1, 1, N, arr[i].first);
  }
  return 0;
}
