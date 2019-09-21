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

vector<int> solution(vector<int> arr, int divisor)
{
	vector<int> answer;
	for (int i = 0; i < (int)arr.size(); ++i) {
		if (arr[i] % divisor == 0) {
			answer.push_back(arr[i]);
		}
	}
	if (!answer.size()) {
		answer.push_back(-1);
	}
	else {
		sort(answer.begin(), answer.end());
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	vector<int> arr = { 5,9,7,10 };
	int divisor = 5;
	vector<int> ret = solution(arr, divisor);

	return 0;
}
