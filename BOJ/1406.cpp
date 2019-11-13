#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <list>
#include <string>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	string s; cin >> s;
	list<char> li;
	for (int i = 0; i < s.length(); ++i)
	{
		li.push_back(s[i]);
	}
	int n; cin >> n;
	auto iter = li.end();
	while (n--)
	{
		char ch; cin >> ch;
		switch (ch)
		{
		case 'L':
		{
			if (iter != li.begin())
				--iter;
			break;
		}
		case 'D':
		{
			if (iter != li.end())
				++iter;
			break;
		}
		case 'B':
		{
			if (iter != li.begin())
			{
				--iter;
				iter = li.erase(iter);
			}
			break;
		}
		case 'P':
		{
			char node; cin >> node;
			li.insert(iter, node);
		}
		default:
			break;
		}
	}
	for (auto out : li)
	{
		cout << out;
	}
	cout << endl;
	return 0;
}
