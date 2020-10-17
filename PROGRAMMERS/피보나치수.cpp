#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int solution(int n)
{
	int dp[100001] = { 0, };
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 1234567;
	}
	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	solution(5);

	return 0;
}
