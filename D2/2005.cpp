#include <iostream>
using namespace std;

const int MAX = 10;

int arr[MAX + 1][MAX + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		int N; cin >> N;
		cout << '#' << cases << '\n';
		arr[1][1] = 1;
		for (int i = 2; i <= N; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]);
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				if (!arr[i][j])
					break;
				else
					cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}