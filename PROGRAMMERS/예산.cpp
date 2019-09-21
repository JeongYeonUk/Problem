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

int solution(vector<int> d, int budget) {
	int answer = 0;
	sort(d.begin(), d.end());
	for (int i = 0; i < (int)d.size(); ++i) {
		if (budget - d[i] < 0)
			break;
		budget -= d[i];
		answer++;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);
	
	cout << solution({ 1,3,2,5,4 },9) << endl;

	return 0;
}
