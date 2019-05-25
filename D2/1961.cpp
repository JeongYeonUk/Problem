#include <iostream>
using namespace std;

const int MAX = 7;

int arr[MAX][MAX];
int N;

void ro_90(int i)
{
	for (int j = N - 1; j >= 0; --j)
	{
		cout << arr[j][i];
	}
}
void ro_180(int i)
{
	for (int j = N - 1; j >= 0; --j)
	{
		cout << arr[i][j];
	}
}
void ro_270(int i)
{
	for (int j = 0; j < N; ++j)
	{
		cout << arr[j][i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> arr[i][j];
			}
		}
		cout << '#' << cases << '\n';
		for (int i = 0; i < N; ++i)
		{
			ro_90(i);
			cout << ' ';
			ro_180(N - i - 1);
			cout << ' ';
			ro_270(N - i - 1);
			cout << '\n';
		}
	}
	return 0;
}