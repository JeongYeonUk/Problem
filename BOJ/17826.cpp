#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int score[51];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	for (int i = 1; i < 51; ++i) {
		cin >> score[i];
	}
	int hong; cin >> hong;

	int cnt = 0;
	for (int i = 1; i < 51; ++i) {
		if (hong == score[i]) {
			cnt = i;
			break;
		}
	}

	string ans = "";
	if (cnt <= 5) ans = "A+";
	else if (cnt <= 15) ans = "A0";
	else if ( cnt <= 30) ans = "B+";
	else if ( cnt <= 35) ans = "B0";
	else if ( cnt <= 45) ans = "C+";
	else if ( cnt <= 48) ans = "C0";
	else ans = "F";

	cout << ans << endl;

	return 0;
}
