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
		int a, b, c, d, e;
		a = b = c = d = e = 0;
		while (true)
		{
			if (N % 2 == 0)
			{
				a++;
				N /= 2;
			}
			else
				break;
		}
		while (true)
		{
			if (N % 3 == 0)
			{
				b++;
				N /= 3;
			}
			else
				break;
		}
		while (true)
		{
			if (N % 5 == 0)
			{
				c++;
				N /= 5;
			}
			else
				break;
		}
		while (true)
		{
			if (N % 7 == 0)
			{
				d++;
				N /= 7;
			}
			else
				break;
		}
		while (true)
		{
			if (N % 11 == 0)
			{
				e++;
				N /= 11;
			}
			else
				break;
		}
		cout << '#' << cases << ' ';
		cout << a << ' ';
		cout << b << ' ';
		cout << c << ' ';
		cout << d << ' ';
		cout << e << '\n';
	}

	return 0;
}