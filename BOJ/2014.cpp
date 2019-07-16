#pragma warning (disable : 4996)
#include <cstdio>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) > (b) ? (b) : (a))

typedef long long ll;
const int INF = 0x7FFFFFFF;
const int MAX_N = 100003;
const int MAX_K = 103;
int N, K;
ll d[MAX_K], idx[MAX_K], r[MAX_N];
struct Node {
  ll val;
  int maxFactor;
  Node(){}
  Node(ll v, int f) : val(v), maxFactor(f){}
};

Node arr[MAX_K];
struct MinHeap {
  int tail, cur, parent, leftIdx, rightIdx;
  ll left, right;
  Node tmp;

  MinHeap() : tail(0){}

  void push(Node node)
  {
    cur = ++tail;
    arr[cur] = node;
    while (true)
    {
      parent = cur >> 1;
      if (cur == 1 || arr[cur].val >= arr[parent].val) break;
      tmp = arr[cur]; arr[cur] = arr[parent]; arr[parent] = tmp;
      cur = parent;
    }
  }

  Node pop()
  {
    Node ret = arr[1];
    arr[1] = arr[tail--];
    cur = 1;
    while (true)
    {
      leftIdx = cur << 1;
      rightIdx = (cur << 1) + 1;
      left = right = INF;

      if (leftIdx <= tail) left = arr[leftIdx].val;
      if (rightIdx <= tail) right = arr[rightIdx].val;

      if (arr[cur].val < left && arr[cur].val < right) break;

      if (left < right)
      {
        tmp = arr[leftIdx]; arr[leftIdx] = arr[cur]; arr[cur] = tmp;
        cur = leftIdx;
      }
      else
      {
        tmp = arr[rightIdx]; arr[rightIdx] = arr[cur]; arr[cur] = tmp;
        cur = rightIdx;
      }
    }
    return ret;
  }

  Node peek()
  {
    return arr[1];
  }

  bool isEmpty()
  {
    return tail == 0;
  }

  int getSize()
  {
    return tail;
  }
};

int main()
{
  MinHeap pq;
  scanf("%d%d", &K, &N);
  for (int i = 0; i < K; ++i)
  {
    scanf("%lld", &d[i]);
    idx[i] = 0;
    pq.push(Node(d[i], i));
  }

  int counter = 1, f;
  Node cur;
  ll prev = -1;
  bool isCounted;
  while (!pq.isEmpty() && counter <= N)
  {
    isCounted = false;
    do {
      cur = pq.pop();
      if (!isCounted)
        r[counter++] = cur.val;
      isCounted = true;
      f = cur.maxFactor;
      pq.push(Node((ll)d[f] * r[++idx[f]], f));
    } while (cur.val == pq.peek().val);
  }
  printf("%lld\n", cur.val);

  return 0;
}
