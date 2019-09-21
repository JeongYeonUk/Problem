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

bool solution(int x) {
	bool answer = true;
	int tmp = x;
	int sum = 0;
	while (tmp) {
		sum += tmp % 10;
		tmp /= 10;
	}
	if (x % sum) {
		answer = false;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution(3721) << endl;

	return 0;
}
