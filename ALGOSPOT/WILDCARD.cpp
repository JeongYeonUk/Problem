#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int cache[100][100];
string wildCard, fileName;

bool matchMemoized(int w, int f)
{
	int& ret = cache[w][f];
	if (ret != -1) return ret;
	if (w < wildCard.size() && f < fileName.size() &&
		(wildCard[w] == '?' || wildCard[w] == fileName[f]))
		return ret = matchMemoized(w + 1, f + 1);

	if (w == wildCard.size() && f == fileName.size())
		return ret = 1;

	if (wildCard[w] == '*')
	{
		if (matchMemoized(w + 1, f) || (f < fileName.size() && matchMemoized(w, f + 1)))
			return ret = 1;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		vector<string> v;
		cin >> wildCard;
		int fileNum; cin >> fileNum;
		for (int i = 0; i < fileNum; ++i)
		{
			memset(cache, -1, sizeof(cache));
			cin >> fileName;
			if (matchMemoized(0, 0))
				v.push_back(fileName);
		}
		sort(v.cbegin(), v.cend());
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << '\n';
		}
		cout << '\n';
	}

	return 0;
}