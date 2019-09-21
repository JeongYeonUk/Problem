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

vector<int> solution(vector<int> arr) {
	int imin = 987654321;
	for (int i = 0; i < (int)arr.size(); ++i) {
		imin = min(imin, arr[i]);
	}
	vector<int> answer;
	for (int i = 0; i < (int)arr.size(); ++i) {
		if (imin == arr[i]) continue;
		answer.push_back(arr[i]);
	}
	if (answer.empty()) {
		answer.push_back(-1);
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	vector<int> ret = solution({4,3,2,1});

	for (auto elem : ret) {
		cout << elem << " ";
	}

	return 0;
}
