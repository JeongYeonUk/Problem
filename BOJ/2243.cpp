#pragma warning (disable : 4996)
#include <cstdio>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) > (b) ? (b) : (a))

typedef long long ll;
const int INF = 0x7FFFFFFF;
const int MAX_N = 1000003;
int N;
int tree[MAX_N * 4];
struct SegTree {
  int size;
  SegTree(int s)
  {
    size = s;
    init(1, 1, size);
  }
  int init(int node, int left, int right)
  {
    if (left == right) return tree[node];
    int mid = (left + right) >> 1;
    return init(node << 1, left, mid) + init((node << 1) + 1, mid + 1, right);
  }
  void update(int node, int left, int right, int idx, int diff)
  {
    if (idx < left || right < idx) return;
    int mid = (left + right) >> 1;
    tree[node] += diff;
    if (left != right)
    {
      update(node, left, mid, idx, diff);
      update(node, mid + 1, right, idx, diff);
    }
  }
  void update(int idx, int diff)
  {
    update(1, 1, size, idx, diff);
  }
  int query(int node, int left, int right, int qleft, int qright)
  {
    if (qright < left || right < qleft) return 0;
    if (qleft <= left && right <= qright) return tree[node];
    int mid = (left + right) >> 1;
    return query(node, left, mid, qleft, qright) +
      query(node, mid + 1, right, qleft, qright);
  }
  int query(int qleft, int qright)
  {
    return query(1, 1, size, qleft, qright);
  }
  int peekAndUpdate(int node, int left, int right, int th, int& ans)
  {
    if (left == right)
    {
      ans = left;
      return --tree[node];
    }
    int l = tree[node << 1];
    int r = tree[(node << 1) + 1];
    int mid = (left + right) >> 1;

    if (th <= l)
      return tree[node] = peekAndUpdate(node << 1, left, mid, th, ans) + r;
    else
    {
      th -= l;
      return tree[node] = peekAndUpdate((node << 1) + 1, mid + 1, right, th, ans) + left;
    }
  }
  int peekAndUpdate(int th, int& ans)
  {
    return peekAndUpdate(1, 1, size, th, ans);
  }
};

int main()
{
  SegTree tree(MAX_N);
  scanf("%d", &N);

  int tmp1, tmp2, tmp3, ans;
  while (N-- > 0)
  {
    scanf("%d", &tmp1);
    if (tmp1 == 1)
    {
      scanf("%d", &tmp2);
      tree.peekAndUpdate(tmp2, ans);
      printf("%d\n", ans);
    }
    else
    {
      scanf("%d%d", &tmp2, &tmp3);
      tree.update(tmp2, tmp3);
    }
  }

  return 0;
}
