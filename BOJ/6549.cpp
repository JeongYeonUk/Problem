#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 100003;

ll arr[MAX_N];
ll tree[MAX_N * 4];
int N;

void init(ll node, ll left, ll right)
{
  if (left == right)
  {
    tree[node] = left;
    return;
  }

  ll mid = (left + right) >> 1;
  init(node * 2, left, mid);
  init(node * 2 + 1, mid + 1, right);
  if (arr[tree[node * 2]] < arr[tree[node * 2 + 1]])
    tree[node] = tree[node * 2];
  else
    tree[node] = tree[node * 2 + 1];
}

ll query(ll node, ll left, ll right, ll qleft, ll qright)
{
  if (qright < left || right < qleft)
    return -1;
  if (qleft <= left && right <= qright)
    return tree[node];

  ll mid = (left + right) >> 1;
  ll m1 = query(node * 2, left, mid, qleft, qright);
  ll m2 = query(node * 2 + 1, mid + 1, right, qleft, qright);

  if (m1 == -1)
    return m2;
  else if (m2 == -1)
    return m1;
  else
  {
    if (arr[m1] <= arr[m2])
      return m1;
    else
      return m2;
  }
}

ll getMax(ll left, ll right)
{
  ll m = query(1, 1, N, left, right);
  ll area = (right - left + 1) * arr[m];

  if (left <= m - 1)
  {
    ll tmp = getMax(left, m - 1);
    if (area < tmp)
      area = tmp;
  }

  if (m + 1 <= right)
  {
    ll tmp = getMax(m + 1, right);
    if (area < tmp)
      area = tmp;
  }
  return area;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  while (true)
  {
    cin >> N;
    if (N == 0)
      break;
    for (int i = 1; i <= N; ++i)
    {
      cin >> arr[i];
    }

    init(1, 1, N);

    cout << getMax(1, N) << '\n';
  }

  return 0;
}
