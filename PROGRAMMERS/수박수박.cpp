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

string solution(int n) {
	string answer = "";
	for (int i = 0; i < n; ++i) {
		if (i & 1) {
			answer += "¹Ú";
		}
		else {
			answer += "¼ö";
		}
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);


	cout << solution(3) << endl;

	return 0;
}
