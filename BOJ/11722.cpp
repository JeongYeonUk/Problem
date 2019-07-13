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
int seq[1001];
int n;

int solve(int start)
{
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n; ++next)
	{
		if (seq[start] > seq[next])
			ret = MAX(ret, solve(next) + 1);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	memset(cache, -1, sizeof(cache));
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = MAX(ans, solve(i));
	cout << ans << '\n';

	return 0;
}
