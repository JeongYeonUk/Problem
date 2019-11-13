#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <list>
#include <vector>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int n, k; cin >> n >> k;
	list<int> li;
	for (int i = 1; i <= n; ++i)
		li.push_back(i);
	auto iter = li.begin();
	for (int i = 0; i < k - 1; ++i)
		iter++;

	vector<int> v;
	while (true)
	{
		if (iter == li.end())
			iter = li.begin();
		v.push_back(*iter);
		iter = li.erase(iter);
		if (iter == li.end())
			iter = li.begin();
		if (li.empty())
			break;
		for (int i = 0; i < k - 1; ++i)
		{
			if (iter == li.end())
				iter = li.begin();
			iter++;
		}
	}
	cout << '<';
	for (int i = 0; i < (int)v.size(); ++i)
	{
		if (i == v.size() - 1)
			cout << v[i];
		else
			cout << v[i] << ", ";
	}
	cout << '>';
	return 0;
}
