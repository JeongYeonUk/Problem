#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int gcd(int a, int b)
{
	return a % b == 0 ? b : gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);
	int a, b; cin >> a >> b;
	cout << gcd(a, b) << endl << lcm(a, b) << endl;
	return 0;
}
