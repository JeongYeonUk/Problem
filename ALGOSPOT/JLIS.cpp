#include <iostream>
#include <numeric>
#include <cstring>
using namespace std;

const long long INF = numeric_limits<long long>::min();
int A[101];
int B[101];
int dp[101][101];
int N,M;

inline int MAX(int a, int b)
{
	return a > b ? a : b;
}

int solve(int indexA, int indexB)
{
	int& ret = dp[indexA+1][indexB+1];
	if (ret != -1)
		return ret;
	ret = 0;
	long long a = (indexA == -1 ? INF : A[indexA]);
	long long b = (indexB == -1 ? INF : B[indexB]);
	long long maxEle = MAX(a, b);
	for (int nextA = indexA + 1; nextA < N; ++nextA)
	{
		if (maxEle < A[nextA])
			ret = MAX(ret, solve(nextA, indexB) + 1);
	}
	for (int nextB = indexB + 1; nextB < M; ++nextB)
	{
		if (maxEle < B[nextB])
			ret = MAX(ret, solve(indexA, nextB) + 1);
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
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
		{
			cin >> A[i];
		}
		for (int i = 0; i < M; ++i)
		{
			cin >> B[i];
		}
		cout << solve(-1, -1) << '\n';
	}

	return 0;
}