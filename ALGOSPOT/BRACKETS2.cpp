#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;

bool solve(const string& input)
{
	const string opening("({["), closeing(")}]");
	stack<char> stk;
	for (int i = 0; i < (int)input.length(); ++i)
	{
		if (opening.find(input[i]) != -1)
		{
			stk.push(input[i]);
		}
		else
		{
			if (stk.empty()) return false;
			if (opening.find(stk.top()) != closeing.find(input[i]))
				return false;
			stk.pop();
		}
	}
	return stk.empty();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		string input; cin >> input;
		if (solve(input))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
