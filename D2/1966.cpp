#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 50;
int arr[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		int N; cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N);
		cout << '#' << cases << ' ';
		for (int i = 0; i < N; ++i)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}