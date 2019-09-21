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

string solution(string s, int n) {
	string answer = "";
	for (int i = 0; i < (int)s.size(); ++i) {
		if (0 <= s[i] - 'a' && s[i] - 'a' <= 25) {
			if (s[i] + n > 122) {
				answer += (s[i] + n) - 26;
			}
			else {
				answer += (s[i] + n);
			}
		}
		else if (0 <= s[i] - 'A' && s[i] - 'A' <= 25) {
			if (s[i] + n > 90) {
				answer += (s[i] + n) - 26;
			}
			else {
				answer += (s[i] + n);
			}
		}
		else if (s[i] == ' ') {
			answer += ' ';
		}
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution("AB",1) << endl;

	return 0;
}
