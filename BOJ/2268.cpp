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
int N, M;

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= M; ++i)
	{
		int a; cin >> a;
		if (a == 0)
		{
			int b, c; cin >> b >> c;
			if (b > c)
				swap(b, c);
			cout << query(1, 1, N, b, c) << '\n';
		}
		else if (a == 1)
		{
			int b, c; cin >> b >> c;
			arr[b] = c;
			update(1, 1, N, b, c);
		}
	}

	return 0;
}
