#include <iostream>
#include <cstring>
using namespace std;

int N;
int h[20001];

inline int MAX(int a, int b)
{
	return a > b ? a : b;
}
inline int MIN(int a, int b)
{
	return a > b ? b : a;
}

int solve(int left, int right)
{
	if (left == right)
		return h[left];
	int mid = ((left + right) >> 1);
	int ret = MAX(solve(left, mid), solve(mid + 1, right));
	int lo = mid, hi = mid + 1;
	int height = MIN(h[lo], h[hi]);
	ret = MAX(ret, (height << 1));
	while (left < lo || hi < right)
	{
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1]))
		{
			++hi;
			height = MIN(height, h[hi]);
		}
		else
		{
			--lo;
			height = MIN(height, h[lo]);
		}
		ret = MAX(ret, height * (hi - lo + 1));
	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		memset(h, 0, sizeof(h));
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> h[i];
		}
		cout << solve(0, N-1) << '\n';
	}

	return 0;
}