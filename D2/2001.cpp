#include <iostream>
using namespace std;

const int MAX = 15;

int arr[MAX][MAX];

int capture(int M, int x, int y)
{
	int sum = 0;
	for (int i = y; i < M + y; ++i)
	{
		for (int j = x; j < M + x; ++j)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		int N, M; cin >> N >> M;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> arr[i][j];
			}
		}
		int max = 0;
		for (int i = 0; i < N - M + 1; ++i)
		{
			for (int j = 0; j < N - M + 1; ++j)
			{
				int ans = capture(M, j, i);
				if (max < ans)
					max = ans;
			}
		}
		cout << '#' << cases << ' ' << max << '\n';
	}

	return 0;
}