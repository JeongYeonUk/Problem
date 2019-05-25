#include <iostream>
using namespace std;

int check[10];

bool solve(int num)
{
	while (num != 0)
	{
		int a = num % 10;
		check[a] = 1;
		num /= 10;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (!check[i])
			return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		for (int i = 0; i < 10; ++i)
			check[i] = 0;
		int N; cin >> N;
		int value = 1;
		while (true)
		{
			if (!solve(value * N))
				value++;
			else
				break;
		}
		cout << '#' << cases << ' ' << value * N << '\n';
	}

	return 0;
}