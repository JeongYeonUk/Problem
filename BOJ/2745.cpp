#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);
	
	string s;
	int b;
	cin >> s >> b;
	ll len = (ll)s.length();
	ll ret = 0;
	for (int i = 0; i < len; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			ret += pow(b, len - i - 1) * (s[i] - '0');
		else
			ret += pow(b, len - i - 1) * (s[i] - 'A' + 10);
	}
	cout << ret << endl;
	return 0;
}
