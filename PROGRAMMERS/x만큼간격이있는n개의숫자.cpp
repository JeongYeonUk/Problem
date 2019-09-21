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

vector<long long> solution(int x, int n) {
	vector<long long> answer;
	for (long long i = 1; i <= n; ++i) {
		answer.push_back(x * i);
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	solution();

	return 0;
}
