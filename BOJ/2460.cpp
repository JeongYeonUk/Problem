#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int out, in;
	int person = 0;
	int ans = 0;
	for (int i = 0; i < 10; ++i) {
		cin >> out >> in;
		person -= out;
		person += in;
		ans = max(ans, person);
	}
	cout << ans << endl;

	return 0;
}
