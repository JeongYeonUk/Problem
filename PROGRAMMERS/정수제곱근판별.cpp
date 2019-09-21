#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

long long solution(long long n) {
	long long answer = 0;
	long long tmp = sqrt(n);
	if (tmp * tmp == n) {
		answer = (tmp + 1) * (tmp + 1);
	}
	else {
		answer = -1;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution(121) << endl;

	return 0;
}
