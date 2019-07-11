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

int cache[1000001];
const int INF = 987654321;
int solve(int n)
{
	if (n == 1)
	{
		return cache[n];
	}
	int& ret = cache[n];
	if (ret != -1) return ret;
	ret = INF;
	if (n % 3 == 0)
		ret = MIN(ret, solve(n / 3) + 1);
	if (n % 2 == 0)
		ret = MIN(ret, solve(n / 2) + 1);
	return ret = MIN(ret, solve(n - 1) + 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	memset(cache, -1, sizeof(cache));
	cache[1] = 0;
	cout << solve(n) << '\n';

	return 0;
}
