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

int solution(int num) {
	int answer = 0;
	long long tmp = num;
	int cnt = 0;
	while (true) {
		if (cnt >= 500) {
			cnt = -1;
			break;
		}
		if (tmp == 1) {
			break;
		}
		if (tmp & 1) {
			tmp *= 3;
			tmp += 1;
		}
		else {
			tmp >>= 1;
		}
		cnt++;
	}
	answer = cnt;
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution(626331) << endl;

	return 0;
}
