#include <iostream>
#include <cstring>
using namespace std;

inline int MAX(int a, int b)
{
	return a > b ? a : b;
}

inline int MIN(int a, int b)
{
	return a > b ? b : a;
}

inline int GCD(int a, int b)
{
	return b == 0 ? a : GCD(b, a % b);
}

inline int CEIL(int a, int b)
{
	return (a + b - 1) / b;
}

int cache[1001];
int rcache[1001];
int seq[1001];
int n;

void solve()
{
	for (int i = 0; i < n; ++i)
	{
		cache[i] = 1;
		for (int j = 0; j <= i; ++j)
		{
			if (seq[i] > seq[j] && cache[j] + 1 > cache[i])
				cache[i] = cache[j] + 1;
		}
	}
}

void rev_solve()
{
	for (int i = n - 1; i >= 0; --i)
	{
		rcache[i] = 1;
		for (int j = n - 1; j >= i; --j)
		{
			if (seq[i] > seq[j] && rcache[j] + 1 > rcache[i])
				rcache[i] = rcache[j] + 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	solve();
	rev_solve();
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = MAX(ans, cache[i] + rcache[i]);
	}
	cout << ans - 1 << '\n';
	return 0;
}
