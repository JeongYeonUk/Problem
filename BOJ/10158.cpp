#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int w, h, p, q, t, x, y;
	cin >> w >> h >> p >> q >> t;

	x = (p + t) / w;
	y = (q + t) / h;

	if (!(x & 1))
		p = (p + t) % w;
	else
		p = w - ((p + t) % w);

	if (!(y & 1))
		q = (q + t) % h;
	else
		q = h - ((q + t) % h);

	cout << p << ' ' << q << endl;

	return 0;
}
