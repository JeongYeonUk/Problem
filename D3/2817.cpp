#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;

int arr[MAX];
int N, K;
int maxDist;
void dfs(int i, int sum)
{
	if (sum > K || i == N)
	{
		if (sum == K) maxDist++;
		return;
	}
	dfs(i + 1, sum + arr[i]);
	dfs(i + 1, sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		maxDist = 0;
		cin >> N >> K;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}
		dfs(0, 0);
		cout << '#' << cases << ' ' << maxDist << '\n';
	}

	return 0;
}