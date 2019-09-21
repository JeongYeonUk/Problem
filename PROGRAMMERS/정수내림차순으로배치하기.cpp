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

long long solution(long long n) {
	long long answer = 0;
	string tmp = to_string(n);
	sort(tmp.begin(), tmp.end(), greater<char>());
	answer = stol(tmp);
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution(118372) << endl;

	return 0;
}
