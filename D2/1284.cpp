#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;

		int A = p * w;
		int B = 0;
		if (w <= r)
			B = q;
		else
		{
			B = q;
			w -= r;
			B += w * s;
		}
		int ans = A >= B ? B : A;
		cout << '#' << cases << ' ' << ans << '\n';
	}

	return 0;
}