#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 1000001;
const int MOD = 1000000007;

int N, M, K;
ll arr[MAX_N];
ll tree[MAX_N * 4];

ll init(ll node, ll left, ll right)
{
	if (left == right)
	{
		return	tree[node] = arr[left];
	}
	ll mid = (left + right) >> 1;
	return tree[node] = (init(node * 2, left, mid)
		* init(node * 2+1, mid + 1, right)) % MOD;
}

ll update(ll node, ll left, ll right, ll idx, ll diff)
{
	if (idx < left || right < idx)
		return tree[node];
	if (left == right)
	{
		return tree[node] = diff;
	}
	ll mid = (left + right) >> 1;
	return tree[node] = (update(node * 2, left, mid, idx, diff)
		* update(node * 2 + 1, mid + 1, right, idx, diff)) % MOD;
}

ll query(ll node, ll left, ll right, ll qleft, ll qright)
{
	if (qright < left || right < qleft)
		return 1;
	if (qleft <= left && right <= qright)
		return tree[node];
	ll mid = (left + right) >> 1;
	return (query(node * 2, left, mid, qleft, qright)
		* query(node * 2 + 1, mid + 1, right, qleft, qright)) % MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	init(1, 1, N);
	for (int i = 1; i <= M + K; ++i)
	{

		int a; cin >> a;
		if (a == 1)
		{
			int b, c; cin >> b >> c;
			arr[b] = c;
			update(1, 1, N, b, c);
		}
		else if (a == 2)
		{
			int b, c; cin >> b >> c;
			cout << query(1, 1, N, b, c)<< '\n';
		}
	}

	return 0;
}
