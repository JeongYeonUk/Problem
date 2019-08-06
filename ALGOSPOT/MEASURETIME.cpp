#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 1000001;

int arr[MAX_N];
int tree[MAX_N];
int N;

int sum(int i)
{
	int ret = 0;
	while (i > 0)
	{
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

void update(int i, int val)
{
	while (i <= N)
	{
		tree[i] += val;
		i += (i & -i);
	}
}

ll solve()
{
	ll ret = 0;
	for (int i = 1; i <= N; ++i)
	{
		ret += sum(N) - sum(arr[i]);
		update(arr[i], 1);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		memset(arr, 0, sizeof(arr));
		memset(tree, 0, sizeof(tree));
		cin >> N;
		for (int i = 1; i <= N; ++i)
			cin >> arr[i];
		cout << solve() << '\n';
	}

	return 0;
}
