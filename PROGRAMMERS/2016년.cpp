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



string solution(int a, int b)
{
	string day[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	string answer = "";

	int ret = 0;
	for (int i = 0; i < a - 1; ++i) {
		ret += month[i];
	}

	ret += b - 1;
	ret %= 7;

	return day[(5 + ret) % 7];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int a = 5;
	int b = 24;

	string ret = solution(a, b);
	cout << ret << endl;
	return 0;
}
