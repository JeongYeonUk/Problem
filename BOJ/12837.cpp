#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 1000001;

ll arr[MAX_N];
ll tree[MAX_N * 4];
int N, Q;

ll update(ll node, ll left, ll right, ll idx, ll value)
{
	if (idx < left || right < idx)
		return tree[node];
	if (left == right)
		return tree[node] += value;
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

	for (int i = 1; i <= Q; ++i)
	{
		int a; cin >> a;
		if (a == 1)
		{
			int p, x; cin >> p >> x;
			update(1, 1, N, p, x);
		}
		else if (a == 2)
		{
			int p, q; cin >> p >> q;
			cout << query(1, 1, N, p, q) << '\n';
		}
	}

	return 0;
}
