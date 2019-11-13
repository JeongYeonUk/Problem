#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <bitset>
#include <vector>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	string s; cin >> s;
	vector<int> ret;

	for (int i = 0; i < (int)s.length(); ++i)
	{
		bitset<3> b = (s[i] - '0');
		for (int i = (int)b.size()-1; i >=0; --i)
		{
			ret.push_back(b[i]);
		}
	}
	for (int i = 0; i < (int)ret.size(); ++i)
	{
		if (!i && (ret[i] == 0))
		{
			continue;
		}
		else
			cout << ret[i];
	}

	return 0;
}
