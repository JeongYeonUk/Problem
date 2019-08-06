#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MOD = 20090711;

struct RNG
{
	int seed, a,  b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983)
	{

	}
	int next()
	{
		int result = seed;
		seed = ((seed * (ll)a) + b) % MOD;
		return result;
	}
};

int solve(int N, RNG rng)
{
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int result = 0;
	for (int cnt = 1; cnt <= N; ++cnt)
	{
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());
		if (!minHeap.empty() && !maxHeap.empty()
			&& minHeap.top() < maxHeap.top())
		{
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		result = (result + maxHeap.top()) % MOD;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		int N, a, b; cin >> N >> a >> b;
		RNG gene(a, b);
		cout << solve(N, gene) << '\n';
	}

	return 0;
}
