#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 500001;
int tree[MAX_N];
int N;

void update(int i)
{
	while (i <= N)
	{
		tree[i] += 1;
		i += (i & -i);
	}
}

int sum(int i)
{
	int ans = 0;
	while (i > 0)
	{
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	vector<int> vcA;
	for (int i = 1; i <= N; ++i)
	{
		int val; cin >> val;
		vcA.push_back(val);
	}

	map<int, int> B;
	for (int i = 1; i <= N; ++i)
	{
		int val; cin >> val;
		B[val] = i;
	}

	ll ans = 0;
	for (int i = 0; i < N; ++i)
	{

		int valA = vcA[i];
		int idxB = B[valA];

		ans += (ll)sum(N) - (ll)sum(idxB);
		update(idxB);

	}

	cout << ans << '\n';

	return 0;
}
