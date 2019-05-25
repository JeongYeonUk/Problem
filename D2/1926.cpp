#include <iostream>
#include <string>
using namespace std;

int clap(const string& str)
{
	int count = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if ((str[i] == '3') || (str[i] == '6') || (str[i] == '9'))
			count++;
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int count = clap(to_string(i));
		if (count)
		{
			for (int i = 0; i < count; ++i)
			{
				cout << '-';
			}
			cout << ' ';
		}
		else
			cout << i << ' ';
	}

	return 0;
}