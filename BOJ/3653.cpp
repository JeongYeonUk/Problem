#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;

struct Segment
{
	int size;
	vector<int> tree, idx;
	Segment(int N, int M)
	{
		size = N + M;
		idx.resize(N);
		tree.resize(size * 4, 0);
	}
	void init(int M)
	{
		init(1, 0, size-1, M);
	}
	int init(int node, int left, int right, int M)
	{
		if (left == right)
		{
			if (left >= M)
			{
				idx[left - M] = left;
				tree[node] = 1;
			}
			return tree[node];
		}
		int mid = (left + right) >> 1;
		return tree[node] = init(node * 2, left, mid, M)
			+ init(node * 2 + 1, mid + 1, right, M);
	}
	int query(int left, int right)
	{
		return query(1, 0, size-1, left, idx[right] - 1);
	}
	int query(int node, int left, int right, int qleft, int qright)
	{
		if (qright < left || right < qleft)
			return 0;
		if (qleft <= left && right <= qright)
		{
			return tree[node];
		}
		int mid = (left + right) >> 1;
		return query(node * 2, left, mid, qleft, qright)
			+ query(node * 2 + 1, mid + 1, right, qleft, qright);
	}
	int update(int index, int val)
	{
		return update(1, 0, size-1, idx[index], val);
	}
	int update(int node, int left, int right, int index, int val)
	{
		if (index < left || right < index)
			return tree[node];
		if (left == right)
			return tree[node] = val;
		int mid = (left + right) >> 1;
		return tree[node] = update(node * 2, left, mid, index, val)
			+ update(node * 2 + 1, mid + 1, right, index, val);
	}
	void change(int index, int val)
	{
		idx[index] = val;
	}
};
int N, M;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--)
	{
		cin >> N >> M;
		Segment seg(N, M);
		seg.init(M);

		int i = M - 1;
		while (M--)
		{
			int u; cin >> u;
			u--;
			cout << seg.query(0, u) << ' ';
			seg.update(u, 0);
			seg.change(u, i--);
			seg.update(u, 1);
		}
		cout << '\n';
	}

	return 0;
}
