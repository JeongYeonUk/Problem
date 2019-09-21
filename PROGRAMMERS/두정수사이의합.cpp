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

ll solution(int a, int b)
{
	ll answer = 0;
	if (a > b) swap(a, b);
	for (ll start = (ll)a; start <= (ll)b; ++start) {
		answer += start;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);
	
	int a = 3; int b = 5;
	ll answer = solution(a,b);
	cout << answer << endl;
	return 0;
}
