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

long long cache[91][2];

long long solve(int n, int before)
{
	if (n == 1)
		return 1;
	long long& ret = cache[n][before];
	if (ret != -1) return ret;
	ret = 0;
	if (before)
		return ret = solve(n - 1, 0);
	else
		return ret = solve(n - 1, 0) + solve(n - 1, 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << solve(n, 1) << '\n';

	return 0;
}
