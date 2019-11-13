#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
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

	ll a, b; cin >> a >> b;
	ll g = gcd(a, b);
	for (ll i = 1; i <= g; ++i)
		cout << 1;
	return 0;
}
