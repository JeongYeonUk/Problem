#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 1000000;
ll arr[MAX_N];
ll tree[MAX_N * 4];
int N, ret, tree_size;
void update(int node, int left, int right, int idx, ll val)
{
  if (idx < left || right < idx)
    return;
  tree[node] += val;

  if (left != right)
  {
    int mid = (left + right) >> 1;
    update(node * 2, left, mid, idx, val);
    update(node * 2 + 1, mid + 1, right, idx, val);
  }
}


ll query(int node, int left, int right, int k)
{
  if ((left == right) && ret == 0)
  {
    cout << left << '\n';
    return left;
  }
  if (ret == 0 && (node * 2 <= tree_size && tree[node * 2] >= k))
    return ret = query(node * 2, left, (left + right) >> 1, k);
  k -= tree[node * 2];
  if(ret == 0 && (node*2+1 <= tree_size && tree[node*2+1] >= k))
    return ret = query(node * 2 + 1, ((left + right) >> 1) + 1, right, k);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int h = (int)ceil(log2(MAX_N));
  tree_size = (1 << (1 + h));

  cin >> N;
  while (N--)
  {
    int A; cin >> A;
    if (A == 2)
    {
      int index; ll val; cin >> index >> val;
      update(1, 0, MAX_N - 1, index, val);
    }
    else if (A == 1)
    {
      int B; cin >> B;
      int getidx = query(1, 0, MAX_N - 1, B);
      ret = 0;
      update(1, 0, MAX_N - 1, getidx, -1);
    }
  }

  return 0;
}
