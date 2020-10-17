#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int solution(int n)
{
	if (n == 1 || n == 2) return 1;

	int left = 1, right = 2;
	int answer = 0;
	int num;
	while (left <= right) {
		num = 0;
		for (int i = left; i <= right; ++i) {
			num += i;
		}
		if (num == n) {
			/*for (int i = left; i <= right; ++i) {
				cout << i << " ";
			}
			cout << endl;*/
			answer++;
			left++;
			if(right < n)
				right++;
		}
		else if (num < n) {
			if (right == n) break;
			right++;
		}
		else if (num > n) {
			if (left == n) break;
			left++;
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution(15) << endl;

	return 0;
}
