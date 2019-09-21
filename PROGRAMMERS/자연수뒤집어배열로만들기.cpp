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

vector<int> solution(long long n) {
	vector<int> answer;
	while (n) {
		answer.push_back(n % 10);
		n /= 10;
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	vector<int> ret = solution(12345);
	for (auto elem : ret) {
		cout << elem << ' ';
	}

	return 0;
}
