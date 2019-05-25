#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000;

int arr[MAX];

int solve(int index)
{
	int ret = 0;
	int max = 0;
	for (int i = index - 2; i <= index + 2; ++i)
	{
		if (index == i)
			continue;
		max = std::max(max, arr[i]);
	}
	ret = arr[index] - max;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int cases = 1; cases <= 10; ++cases)
	{
		int N; cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}
		int ans = 0;
		for (int i = 2; i < N - 2; ++i)
		{
			if (arr[i - 1] >= arr[i] || arr[i - 2] >= arr[i])
			{
				continue;
			}
			if (arr[i + 1] >= arr[i] || arr[i + 2] >= arr[i])
			{
				continue;
			}
			ans += solve(i);
		}
		cout << '#' << cases << ' ' << ans << '\n';
	}

	return 0;
}