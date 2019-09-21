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

string solution(string phone_number) {
	string answer = "";
	int len = phone_number.length();
	for (int i = 0; i < len - 4; ++i) {
		answer += '*';
	}
	for (int i = len - 4; i < len; ++i) {
		answer += phone_number[i];
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution("01033334444") << endl;

	return 0;
}
