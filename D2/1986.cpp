#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		int N; cin >> N;
		int ans = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (i % 2 == 0)
				ans -= i;
			else
				ans += i;
		}
		cout << '#' << cases << ' ' << ans << '\n';
	}

	return 0;
}