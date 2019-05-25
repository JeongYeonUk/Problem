#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		string s; cin >> s;
		int index = 0;
		bool flag = true;
		for (int i = s.length() - 1; i >= 0; --i)
		{
			if (s[i] != s[index])
			{
				flag = false;
				break;
			}
			else
			{
				index++;
			}
		}
		cout << '#' << cases << ' ';
		if (flag)
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}