#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> a(10);
	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		for (int i = 0; i < 10; ++i)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int sum = 0;
		for (int i = 1; i < 9; ++i)
		{
			sum += a[i];
		}
		int ans = (int)floor(((double)sum / 8) + 0.5);
		cout << '#' << cases << ' ' << ans << '\n';
	}

	return 0;
}