#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool solution(string s)
{
	bool answer = true;
	int p = 0; int y = 0;
	for (int i = 0; i < (int)s.length(); ++i) {
		if (s[i] == 'p' || s[i] == 'P') {
			p++;
		}
		else if (s[i] == 'y' || s[i] == 'Y') {
			y++;
		}
	}
	if (p == y) {
		answer = true;
	}
	else {
		answer = false;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);
	string s = "pPoooyY";
	cout << solution(s) << endl;

	return 0;
}
