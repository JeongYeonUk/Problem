#include <iostream>
using namespace std;

int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		int a, b, c, d; cin >> a >> b >> c >> d;
		int ans = 0;
		for (int i = a; i < c; ++i)
		{
			ans += day[i];
		}
		ans += (d - b + 1);
		cout << '#' << cases << ' ' << ans << '\n';
	}

	return 0;
}