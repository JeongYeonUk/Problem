#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

inline int MAX(int a, int b)
{
	return a > b ? a : b;
}

inline int MIN(int a, int b)
{
	return a > b ? b : a;
}

int len[101];
int n;

int strjoin()
{
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < n; ++i)
		pq.push(len[i]);
	int ret = 0;
	while (pq.size() > 1)
	{
		int min1 = pq.top(); pq.pop();
		int min2 = pq.top(); pq.pop();
		pq.push(min1 + min2);
		ret += min1 + min2;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> len[i];
		}
		cout << strjoin() << '\n';
	}

	return 0;
}
