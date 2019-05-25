#include <iostream>
using namespace std;

pair<char, int> arr[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		int N; cin >> N;
		int sum = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i].first >> arr[i].second;
			sum += arr[i].second;
		}
		cout << '#' << cases << '\n';
		int index = 0;
		for (int i = 0; i < sum; ++i)
		{
			if ((i != 0) && (i % 10 == 0))
				cout << '\n';
			if (arr[index].second < 1)
				index++;
			cout << arr[index].first;
			arr[index].second--;
		}
	}

	return 0;
}