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

const int MOD = 1000000000;
int cache[101][10];
int solve(int n, int start)
{
	if (n == 1)
		return 1;
	int& ret = cache[n][start];
	if (ret != -1) return ret;
	if (start == 0)
		return ret = solve(n - 1, start + 1) % MOD;
	else if (start == 9)
		return ret = solve(n - 1, start - 1) % MOD;
	else
		return ret = (solve(n - 1, start - 1) + solve(n - 1, start + 1)) % MOD;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	memset(cache, -1, sizeof(cache));
	int ans = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (!i) continue;
		ans  = (ans + solve(n, i)) % MOD;
	}
	cout << ans << '\n';
	return 0;
}
