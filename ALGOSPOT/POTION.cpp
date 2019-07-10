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

int n;
int recipe[1001];
int put[1001];
int result[1001];

void solve()
{
	int b = recipe[0];
	for (int i = 0; i < n; ++i)
	{
		b = GCD(b, recipe[i]);
	}
	int a = b;
	for (int i = 0; i < n; ++i)
	{
		a = MAX(a, CEIL(put[i] * b, recipe[i]));
	}
	for (int i = 0; i < n; ++i)
	{
		result[i] = recipe[i] * a / b - put[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> recipe[i];
		for (int i = 0; i < n; ++i)
			cin >> put[i];
		solve();
		for (int i = 0; i < n; ++i)
			cout << result[i] << ' ';
		cout << '\n';
	}

	return 0;
}
