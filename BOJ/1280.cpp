#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 200003;
const ll MOD = 1e9 + 7;
int N;
ll arr[MAX_N];
ll cntTree[MAX_N];
ll sumTree[MAX_N];

ll _sum(ll* tree, ll i)
{
	ll ret = 0;
	while (i > 0)
	{
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

ll sum(ll* tree, ll s, ll e)
{
	if (s > e) return 0;
	return (_sum(tree, e) - _sum(tree, s - 1));
}

void update(ll* tree, ll i, ll val)
{
	while (i <= MAX_N)
	{
		tree[i] += val;
		i += (i & -i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		ll x; cin >> x;
		x += 1;
		if (i == 1)
		{
			update(cntTree, x, 1LL);
			update(sumTree, x, x);
		}
		else
		{
			arr[i] += sum(sumTree, x + 1, MAX_N)
				- x * sum(cntTree, x + 1, MAX_N);
			arr[i] += sum(cntTree, 1, x - 1) * x
				- sum(sumTree, 1, x - 1);
			arr[i] %= MOD;
			update(cntTree, x, 1LL);
			update(sumTree, x, x);
		}
	}
	ll ret = 1;
	for (int i = 2; i <= N; ++i)
	{
		ret *= arr[i];
		ret %= MOD;
	}
	cout << ret << '\n';
	return 0;
}
