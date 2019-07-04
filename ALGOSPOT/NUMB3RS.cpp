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

int n, d, p, q;
double cache[51][101];
int connected[51][51], deg[51];
int vil[51];

double search(int here, int days)
{
	if (days == 0)
		return (here == p ? 1.0 : 0.0);
	double& ret = cache[here][days];
	if (ret != -1.0) return ret;
	ret = 0.0;
	for (int there = 0; there < n; ++there)
	{
		if (connected[here][there])
			ret += search(there, days - 1) / deg[there];
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		cin >> n >> d >> p;
		memset(deg, 0, sizeof(deg));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> connected[i][j];				
			}
		}
		for (int i = 0; i < 51; ++i)
		{
			for (int j = 0; j < 101; ++j)
			{
				cache[i][j] = -1.0;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				deg[i] += connected[i][j];
			}
		}
		cin >> q;
		for (int i = 0; i < q; ++i)
		{
			cin >> vil[i];
		}
		for (int i = 0; i < q; ++i)
		{
			cout.precision(8);
			cout << search(vil[i], d) << ' ';
		}
		cout << '\n';
	}

	return 0;
}
