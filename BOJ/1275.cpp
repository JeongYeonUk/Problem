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

int N, Q;
ll arr[MAX_N];
ll tree[MAX_N * 4];

ll init(ll node, ll left, ll right)
{
	if (left == right)
		return tree[node] = arr[left];
	ll mid = (left + right) >> 1;
	return tree[node] = init(node * 2, left, mid)
		+ init(node * 2 + 1, mid + 1, right);
}

ll update(ll node, ll left, ll right, ll idx, ll value)
{
	if (idx < left || right < idx)
		return tree[node];
	if (left == right)
		return tree[node] = value;
	ll mid = (left + right) >> 1;
	return tree[node] = update(node * 2, left, mid, idx, value)
		+ update(node * 2 + 1, mid + 1, right, idx, value);
}

ll query(ll node, ll left, ll right, ll qleft, ll qright)
{
	if (qright < left || right < qleft)
		return 0;
	if (qleft <= left && right <= qright)
		return tree[node];

	ll mid = (left + right) >> 1;
	return query(node * 2, left, mid, qleft, qright)
		+ query(node * 2 + 1, mid + 1, right, qleft, qright);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> Q;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	init(1, 1, N);
	for (int i = 1; i <= Q; ++i)
	{
		int x, y, a, b; cin >> x >> y >> a >> b;
		if (x < y)
		{
			cout << query(1, 1, N, x, y) << '\n';
		}
		else
		{
			cout << query(1, 1, N, y, x) << '\n';
		}
		arr[a] = b;
		update(1, 1, N, a, b);
	}

	return 0;
}
