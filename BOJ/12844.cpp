#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 500001;

int N,M;

struct Segment
{
  ll size;
  vector<ll> arr, tree, lazy;
  Segment(int n) : size(n)
  {
    arr.resize(size, 0);
    tree.resize(size * 4, 0);
    lazy.resize(size * 4, 0);
  }
  ll init(int node, int left, int right)
  {
    if (left == right)
    {
      return tree[node] = arr[left];
    }
    int mid = (left + right) >> 1;
    return tree[node] = init(node * 2, left, mid)
      ^ init(node * 2 + 1, mid + 1, right);
  }
  void init()
  {
    init(1, 0, size - 1);
  }
  void update_lazy(int node, int left, int right)
  {
    if (lazy[node] == 0)
      return;

    tree[node] ^= ((right - left + 1) % 2) * lazy[node];

    if (left != right)
    {
      lazy[node * 2] ^= lazy[node];
      lazy[node * 2 + 1] ^= lazy[node];
    }
    lazy[node] = 0;
  }
  void update_range(int node, int left, int right, int uleft, int uright, ll val)
  {
    update_lazy(node, left, right);
    if (uright < left || right < uleft)
      return;
    if (uleft <= left && right <= uright)
    {
      tree[node] ^= ((right - left + 1)%2) * val;
      if (left != right)
      {
        lazy[node * 2] ^= val;
        lazy[node * 2 + 1] ^= val;
      }
      return;
    }
    int mid = (left + right) >> 1;
    update_range(node * 2, left, mid, uleft, uright, val);
    update_range(node * 2 + 1, mid + 1, right, uleft, uright, val);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
  }
  void update(int uleft, int uright, ll val)
  {
    update_range(1, 0, size - 1, uleft, uright, val);
  }
  ll query(int node, int left, int right, int qleft, int qright)
  {
    update_lazy(node, left, right);
    if (qright < left || right < qleft)
      return 0;
    if (qleft <= left && right <= qright)
      return tree[node];
    int mid = (left + right) >> 1;
    return query(node * 2, left, mid, qleft, qright)
      ^ query(node * 2 + 1, mid + 1, right, qleft, qright);
  }
  ll query(int qleft, int qright)
  {
    return query(1, 0, size - 1, qleft, qright);
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cin >> N;
  Segment seg(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> seg.arr[i];
  }
  seg.init();
  cin >> M;
  for (int i = 0; i < M; ++i)
  {
    int t; cin >> t;
    if (t == 1)
    {
      int a, b; ll c; cin >> a >> b >> c;
      if (a > b)
        swap(a, b);
      seg.update(a, b, c);
    }
    else if (t == 2)
    {
      int a, b; cin >> a >> b;
      if (a > b)
        swap(a, b);
      cout << seg.query(a, b) << '\n';
    }
  }

  return 0;
}
