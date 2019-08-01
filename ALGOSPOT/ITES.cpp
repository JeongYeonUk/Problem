#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MOD = 10000;
int K, N;

struct RNG
{
	unsigned seed;
	RNG() : seed(1983)
	{
	}
	unsigned next()
	{
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % MOD + 1;
	}
};

int solve()
{
	RNG rng;
	queue<int> range;
	int ret = 0, sum = 0;
	for (int i = 0; i < N; ++i)
	{
		int newSignal = rng.next();
		sum += newSignal;
		range.push(newSignal);

		while (sum > K)
		{
			sum -= range.front();
			range.pop();
		}

		if (sum == K)
			ret++;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> K >> N;
		cout << solve() << '\n';
	}

	return 0;
}
