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

string solution(string s) {
	string answer = "";
	int idx = 0;
	for (int i = 0; i < (int)s.length(); ++i) {
		if (s[i] == ' ') {
			idx = 0;
			continue;
		}
		if (idx & 1) {
			if (0 <= s[i] - 'A' && s[i] - 'A' <= 25) {
				s[i] = tolower(s[i]);
			}
		}
		else {
			if (0 <= s[i] - 'a' && s[i] - 'a' <= 25) {
				s[i] = toupper(s[i]);
			}
		}
		idx++;
	}
	answer = s;
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution("try hello world") << endl;

	return 0;
}
