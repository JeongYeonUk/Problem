#include <iostream>
using namespace std;

typedef long long ll;
const int MAX_N = 1000003;
int N, M, K;
ll arr[MAX_N], tree[MAX_N * 4];

ll init(int node, int left, int right)
{
  if (left == right)
  {
    return tree[node] = arr[left];
  }
  int mid = ((left + right) >> 1);
  ll left_val = init((node << 1), left, mid);
  ll right_val = init((node << 1) + 1, mid + 1, right);

  return tree[node] = left_val + right_val;
}

ll query(int node, int left, int right, int qs, int qe)
{
  if (qs <= left && right <= qe)
    return tree[node];
  if (qe < left || right < qs)
    return 0LL;
  int mid = ((left + right) >> 1);
  ll left_val = query((node << 1), left, mid, qs, qe);
  ll right_val = query((node << 1) + 1, mid + 1, right, qs, qe);
  return left_val + right_val;
}

void update(int node, int left, int right, ll idx, ll diff)
{
  if (idx < left || idx > right)
    return;
  if (idx >= left && idx <= right)
    tree[node] += diff;
  if (left != right)
  {
    int mid = ((left + right) >> 1);
    update((node << 1), left, mid, idx, diff);
    update((node << 1) + 1, mid + 1, right, idx, diff);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M >> K;
  for (int i = 1; i <= N; ++i)
  {
    cin >> arr[i];
  }
  init(1, 1, N);

  ll a, b, c;
  for (int i = 0; i < M + K; ++i)
  {
    cin >> a >> b >> c;
    if (a == 1)
    {
      ll diff = c - arr[b];
      arr[b] = c;
      update(1, 1, N, b, diff);
    }
    else if (a == 2)
    {
      ll ret = query(1, 1, N, b, c);
      cout << ret << '\n';
    }
  }

  return 0;
}
