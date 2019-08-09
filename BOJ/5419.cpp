#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 100001;

int tree[MAX_N * 4];
int b[MAX_N];
pii arr[MAX_N];
int N;

bool cmp(pii a, pii b)
{
  if (a.first == b.first)
    return a.second > b.second;
  return a.first < b.first;
}

int update(int node, int left, int right, int idx, int val)
{
  if (idx < left || right < idx)
    return tree[node];
  if (left == right)
    return tree[node] = val;
  int mid = (left + right) >> 1;
  return tree[node] = update(node * 2, left, mid, idx, val)
    + update(node * 2 + 1, mid + 1, right, idx, val);
}

int query(int node, int left, int right, int qleft, int qright)
{
  if (qright < left || right < qleft)
    return 0;
  if (qleft <= left && right <= qright)
    return tree[node];
  int mid = (left + right) >> 1;
  return query(node * 2, left, mid, qleft, qright)
    + query(node * 2 + 1, mid + 1, right, qleft, qright);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int T; cin >> T;
  while (T--)
  {
    memset(tree, 0, sizeof(tree));
    memset(b, 0, sizeof(b));
    long long res = 0;
    cin >> N;
    vector<int> ypos;
    for (int i = 1; i <= N; ++i)
    {
      int x, y; cin >> x >> y;
      arr[i] = { x,y };
      ypos.push_back(y);
    }
    sort(arr + 1, arr + N + 1, cmp);
    sort(ypos.begin(), ypos.end());
    ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());
    for (int i = 1; i <= N; ++i)
    {
      int z = lower_bound(ypos.begin(), ypos.end(), arr[i].second) - ypos.begin();
      res += (ll)query(1, 0, N - 1, z, N - 1);
      b[z]++;
      update(1, 0, N - 1, z, b[z]);
    }
    cout << res << '\n';
  }

  return 0;
}
