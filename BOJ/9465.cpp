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

int cache[100001][3];
int sticker[2][100001];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> sticker[i][j];
			}
		}

		cache[0][0] = 0;
		cache[0][1] = sticker[0][0];
		cache[0][2] = sticker[1][0];
		for (int i = 1; i < n; ++i)
		{
			cache[i][0] = MAX(MAX(cache[i-1][0], cache[i-1][1]), cache[i-1][2]);
			cache[i][1] = MAX(cache[i-1][0], cache[i-1][2]) + sticker[0][i];
			cache[i][2] = MAX(cache[i-1][0], cache[i-1][1]) + sticker[1][i];
		}
		cout << MAX(MAX(cache[n - 1][0], cache[n - 1][1]), cache[n - 1][2]) << '\n';
	}
	return 0;
}
