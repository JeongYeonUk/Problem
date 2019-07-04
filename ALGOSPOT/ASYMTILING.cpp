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

const int MOD = 1000000007;
int cache[101];

int tiling(int width)
{
	if (width <= 1) return 1;
	int& ret = cache[width];
	if (ret != -1) return ret;
	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}

int asymtiling(int width)
{
	if (width & 1)
		return (tiling(width) - tiling((width >> 1)) + MOD) % MOD;
	int ret = tiling(width);
	ret = (ret - tiling((width >> 1)) + MOD) % MOD;
	ret = (ret - tiling((width >> 1) - 1) + MOD) % MOD;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		int N;
		cin >> N;
		memset(cache, -1, sizeof(cache));
		cout << asymtiling(N) << '\n';
	}

	return 0;
}
