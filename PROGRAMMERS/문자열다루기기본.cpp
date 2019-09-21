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

string solution(vector<string> seoul) {
	string answer = "김서방은 ";
	for (int i = 0; i < (int)seoul.size(); ++i) {
		if (seoul[i] == "Kim") {
			answer += to_string(i);
			break;
		}
	}
	answer += "에 있다";
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	vector<string> seoul = { "Jane", "Kim" };
	cout << solution(seoul) << endl;

	return 0;
}
