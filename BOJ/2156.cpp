#include <iostream>
#include <cstring>
using namespace std;

inline long long MAX(long long a, long long b)
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

long long cache[10001];
long long grape[10001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> grape[i];

	cache[1] = grape[1];
	cache[2] = grape[2] + grape[1];
	for (int i = 3; i <= n; ++i)
	{
		cache[i] = cache[i - 1];
		cache[i] = MAX(cache[i], cache[i - 2] + grape[i]);
		cache[i] = MAX(cache[i], cache[i - 3] + grape[i] + grape[i-1]);
	}

	cout << cache[n] << '\n';
	
	return 0;
}
