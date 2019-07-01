#include <iostream>
#include <cstring>
using namespace std;

int N;
int arr[500];
int dp[500];

inline int MAX(int a, int b)
{
	return a > b ? a : b;
}

int solve(int start)
{
	int& ret = dp[start];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int next = start + 1; next < N; ++next)
	{
		if(arr[start] < arr[next])
			ret = MAX(ret, solve(next) + 1);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		memset(dp, -1, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}
		int maxLen = 0;
		for (int i = 0; i < N; ++i)
		{
			maxLen = MAX(maxLen, solve(i));
		}
		cout << maxLen << '\n';
	}

	return 0;
}