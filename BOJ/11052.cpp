#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 1001;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int arr[MAX_N];
int d[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}
	d[1] = arr[1];
	for (int n = 2; n <= N; ++n)
	{
		for (int l = 1; l <= n; ++l)
		{
			d[n] = max(d[n], d[n - l] + arr[l]);
		}
	}

	cout << d[N] << '\n';

	return 0;
}
