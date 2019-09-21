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

string solution(string s)
{
	string answer = "";
	int length = (s.length() >> 1);
	if (s.length() & 1) {
		answer = s[length];
	}
	else {
		answer += s[length - 1];
		answer += s[length];
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	string s = "qwer";
	string ret = solution(s);
	cout << ret << endl;
	return 0;
}
