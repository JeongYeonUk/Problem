#include <iostream>
#include <vector>
#include <string>
using namespace std;

string solve(string::iterator& it)
{
	char head = *it;
	it++;

	if (head == 'b' || head == 'w')
		return string(1, head);

	vector<string> arr(4);
	for (int i = 0; i < 4; ++i)
	{
		arr[i] = solve(it);
	}

	return 'x' + arr[2] + arr[3] + arr[0] + arr[1];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		string s; cin >> s;
		string::iterator it = s.begin();
		cout << solve(it) << '\n';
	}

	return 0;
}