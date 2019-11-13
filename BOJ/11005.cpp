#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<int> v;
	while (n)
	{
		v.push_back(n % k);
		n /= k;
	}
	reverse(v.begin(), v.end());

	for (int i = 0; i < (int)v.size(); ++i)
	{
		if (v[i] >= 10)
		{
			cout << (char)((v[i] - 10) + 'A');
		}
		else
			cout << v[i];
	}
	return 0;
}
