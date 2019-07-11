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

int cache[11];

int solve(int n)
{
	if (n == 0)
		return 1;
	int& ret = cache[n];
	if (ret != -1) return ret;
	return ret = solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		int n; cin >> n;
		memset(cache, -1, sizeof(cache));
		cout << solve(n) << '\n';
	}

	return 0;
}
