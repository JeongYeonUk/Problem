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

int solution(vector<int> A, vector<int> B)
{
	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());

	int answer = 0;
	for (int i = 0; i < (int)A.size(); ++i) {
		answer += (A[i] * B[i]);
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution({ 1,4,2 }, { 5,4,4 }) << endl;

	return 0;
}
