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

const int MOD = 10000000;
int cache[101][101];

int poly(int n, int first)
{
	if (n == first) return 1;
	int& ret = cache[n][first];
	if (ret != -1) return ret;
	ret = 0;
	for (int second = 1; second <= n - first; ++second)
	{
		int add = second + first - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		int block, sum = 0;
		cin >> block;
		memset(cache, -1, sizeof(cache));
		for (int i = 1; i <= block; ++i)
		{
			sum += poly(block, i);
			sum %= MOD;
		}
	}

	return 0;
}
