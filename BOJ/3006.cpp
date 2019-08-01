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

pii arr[MAX_N];
int tree[MAX_N];
int N;

void update(int i, int diff)
{
	while (i <= N)
	{
		tree[i] += diff;
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
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i].first;
		arr[i].second = i;
		update(i, 1);
	}

	sort(arr + 1, arr + N + 1);

	int p1 = 1, p2 = N;
	for (int i = 1; i <= N; ++i)
	{
		if (i %2 ==1)
		{
			cout << sum(arr[p1].second) - 1 << '\n';
			update(arr[p1].second, -1);
			p1++;
		}
		else
		{
			cout << sum(N) - sum(arr[p2].second - 1) - 1 << '\n';
			update(arr[p2].second, -1);
			p2--;
		}
	}

	return 0;
}
