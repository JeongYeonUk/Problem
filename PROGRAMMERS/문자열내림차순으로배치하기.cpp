#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <functional>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string solution(string s)
{
	string answer = s;
	sort(answer.begin(), answer.end(), greater<char>());
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	string s = "Zbcdefg";
	cout << solution(s) << endl;

	return 0;
}
