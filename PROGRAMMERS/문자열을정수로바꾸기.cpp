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

int solution(string s) {
	int answer = 0;
	if (s[0] == '-') {
		string tmp(s.begin() + 1, s.end());
		answer = stoi(s);
		answer = -answer;
	}
	else {
		answer = stoi(s);
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution("-1234") << endl;

	return 0;
}
