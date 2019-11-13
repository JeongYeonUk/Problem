#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 100001;

int arr[MAX];
int tree[MAX * 4];
int n, k;

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

int query(int node, int left, int right, int val)
{
	int mid = (left + right) >> 1;
	if (left == right)
		return left;
	if (tree[node * 2] >= val)
		return query(node * 2, left, mid, val);
	return query(node * 2 + 1, mid + 1, right, val - tree[node*2]);
}

int squery(int node, int left, int right, int qleft, int qright)
{
	if (qright < left || right < qleft)
		return 0;
	if (qleft <= left && right <= qright)
		return tree[node];
	int mid = (left + right) >> 1;
	return squery(node * 2, left, mid, qleft, qright)
		+ squery(node * 2 + 1, mid + 1, right, qleft, qright);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);
	int n, k; cin >> n >> k;
	vector<int> ans;
	for (int i = 1; i <= n; ++i)
		update(1, 1, n, i, 1);
	int mod = n - 1;
	ans.push_back(k);
	update(1, 1, n, k, 0);
	for (int i = 2; i <= n; ++i)
	{
		int ret = (squery(1, 1, n, 1, ans.back()) + k) % mod;
		if (!ret)
			ret = mod;
		ans.push_back(query(1, 1, n, ret));
		update(1, 1, n, ans.back(), 0);
		mod--;
	}
	cout << '<';
	for (int i = 0; i < (int)ans.size(); ++i)
	{
		if (i == ans.size() - 1)
			cout << ans[i] << ">" << endl;
		else
			cout << ans[i] << ", ";
	}
	return 0;
}
