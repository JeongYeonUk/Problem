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

int arr[1000000];

void era() {
	for (int i = 2; i < 1000000; ++i) {
		if (arr[i]) continue;
		for (int j = i + i; j < 1000000; j += i) {
			if (!arr[j])
				arr[j] = 1;
		}
	}
}

int solution(int n)
{
	era();
	int answer = 0;
	for (int i = 2; i <= n; ++i) {
		if (!arr[i])
			answer++;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution(10);

	return 0;
}
