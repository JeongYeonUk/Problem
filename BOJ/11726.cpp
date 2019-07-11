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

int solve(int width)
{
	if (width <= 1)
	{
		return 1;
	}
	int& ret = cache[width];
	if (ret != -1) return ret;
	ret = 0;
	return ret = (solve(width - 1) + solve(width - 2)) % 10007;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	memset(cache, -1, sizeof(cache));
	cache[1] = 1;
	cout << solve(n)<< '\n';
	return 0;
}
