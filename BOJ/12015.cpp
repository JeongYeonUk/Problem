#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 1000001;

int arr[MAX_N];
int cache[MAX_N];
int N;

int lis()
{
	int idx = 0;
	cache[idx] = arr[idx];
	for (int i = 1; i < N; ++i)
	{
		if (cache[idx] < arr[i])
		{
			cache[++idx] = arr[i];
		}
		else
		{
			int lb = lower_bound(cache, cache + idx, arr[i]) - cache;
			cache[lb] = arr[i];
		}
	}
	return idx + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	cout << lis() << '\n';

	return 0;
}
