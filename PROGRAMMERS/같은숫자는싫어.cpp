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

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	answer.push_back(arr[0]);
	for (int i = 1; i < (int)arr.size(); ++i) {
		if (answer.back() != arr[i]) {
			answer.push_back(arr[i]);
		}
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	vector<int> arr = { 1,1,3,3,0,1,1 };
	vector<int> ret = solution(arr);

	for (int i = 0; i < (int)ret.size(); ++i) {
		cout << ret[i] << ", ";
	}

	return 0;
}
