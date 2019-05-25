#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;

int arr[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int cases = 1; cases <= 100; ++cases)
	{
		int N; cin >> N;
		for (int i = 0; i < MAX; ++i)
			cin >> arr[i];
		int highest = 0; int lowest = 0;
		for (int i = 0; i <= N; ++i)
		{
			for (int j = 0; j < 100; ++j)
			{
				if (arr[j] > arr[highest]) highest = j;
				if (arr[j] < arr[lowest]) lowest = j;
			}
			int temp = arr[highest] - arr[lowest];
			if (temp == 1 || temp == 0) break;
			if (i == N) break;
			arr[highest]--;
			arr[lowest]++;
		}

		cout << '#' << cases << ' ' << arr[highest] - arr[lowest] << '\n';
	}

	return 0;
}