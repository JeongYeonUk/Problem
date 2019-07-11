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

const int MOD = 10007;
int cache[10][1001];

int solve(int n)
{
	for (int i = 0; i < 10; ++i)
		cache[i][1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = j; k < 10; ++k)
			{
				cache[j][i] += cache[k][i - 1];
				cache[j][i] %= MOD;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; ++i)
		sum += cache[i][n];
	return sum % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	memset(cache, 0, sizeof(cache));
	
	cout << solve(n) << '\n';
	return 0;
}
