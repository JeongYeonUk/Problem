#include <iostream>
using namespace std;

int a[8];
int money[8];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;

	money[0] = 50000;
	money[1] = 10000;
	money[2] = 5000;
	money[3] = 1000;
	money[4] = 500;
	money[5] = 100;
	money[6] = 50;
	money[7] = 10;

	for (int cases = 1; cases <= T; ++cases)
	{
		int N; cin >> N;

		for (int i = 0; i < 8; ++i)
		{
			a[i] = N / money[i];
			N %= money[i];
		}
		cout << '#' << cases << '\n';
		for (int i = 0; i < 8; ++i)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}