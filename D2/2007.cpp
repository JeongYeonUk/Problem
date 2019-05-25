#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(const string& s, const string& temp)
{
	int length = temp.length() * 2;
	for (int i = 0; i < length; i += temp.length())
	{
		int index = i;
		for (int j = 0; j < temp.length(); ++j)
		{
			if (s[index] != temp[j])
				return false;
			index++;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		string s; cin >> s;
		int ans = 0;
		for (int k = 1; k <= 10; ++k)
		{
			string temp(s.begin(), s.begin() + k);
			if (compare(s, temp))
			{
				ans = temp.length();
				break;
			}
		}
		cout << '#' << cases << ' ' << ans << '\n';
	}
	return 0;
}