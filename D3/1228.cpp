#pragma warning (disable : 4996)
#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	for (int cases = 1; cases <= 10; ++cases)
	{
		int first; cin >> first;
		list<int> ans;
		for (int i = 0; i < first; ++i)
		{
			int val; cin >> val;
			ans.push_back(val);
		}
		int second; cin >> second;
		for (int k = 0; k < second; ++k)
		{
			auto iter = ans.begin();
			list<int> temp;
			char c; cin >> c;
			int in; cin >> in;
			for (int i = 0; i < in; ++i)
			{
				iter++;
			}
			int count; cin >> count;
			for (int i = 0; i < count; ++i)
			{
				int val; cin >> val;
				temp.push_back(val);
			}
			ans.insert(iter, temp.begin(), temp.end());
		}
		int count = 0;
		auto iter = ans.begin();
		cout << '#' << cases << ' ';
		while (count != 10)
		{
			cout << *iter << ' ';
			iter++;
			count++;
		}
		cout << '\n';
	}

	return 0;
}