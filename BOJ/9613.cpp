#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

ll gcd(ll a, ll b)
{
	return a % b == 0 ? b : gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int n; cin >> n;
	for (int c = 0; c < n; ++c)
	{
		int num; cin >> num;
		vector<ll> a;
		a.resize(num);
		for (int i = 0; i < num; ++i)
			cin >> a[i];
		ll ret = 0;
		for (int i = 0; i < num; ++i)
		{
			for (int j = i+1; j < num; ++j)
			{
				ret += gcd(a[i], a[j]);
			}
		}
		cout << ret << endl;
	}

	return 0;
}
