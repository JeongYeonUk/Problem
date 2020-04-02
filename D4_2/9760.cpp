#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define endl '\n'
#define X second
#define Y first

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;

int number[256];
string ans[10];
vector<string> card;



bool cmp(string a, string b) {
	int A = number[a[1]];
	int B = number[b[1]];

	if (A == B)
		return A > B;
	return A < B;
}

bool full_house() {
	int check[14] = { 0, };
	for (int i = 0; i < 5; ++i) {
		check[number[card[i][1]]]++;
	}
	int cnt_three = 0, cnt_two = 0;
	for (int i = 1; i < 14; ++i) {
		if (check[i] == 2)
			cnt_two++;
		if (check[i] == 3)
			cnt_three++;
	}
	if (cnt_two && cnt_three)
		return true;
	return false;
}

bool four_three_card(int num) {
	for (int i = 0; i < 5; ++i) {
		int cnt = 1;
		for (int j = 0; j < 5; ++j) {
			if (i == j) continue;
			if (card[i][1] == card[j][1]) {
				cnt++;
			}
		}
		if (cnt == num) {
			return true;
		}
	}
	return false;
}

int pair_card() {
	int check[14] = { 0, };
	for (int i = 0; i < 5; ++i) {
		check[number[card[i][1]]]++;
	}
	int cnt = 0;
	for (int i = 1; i < 14; ++i) {
		if (check[i] == 2)
			cnt++;
	}
	if (cnt == 2) {
		return 7;
	}
	else if (cnt == 1) {
		return 8;
	}
	else {
		return -1;
	}
}

bool royal() {
	int check[4] = {0,};
	if (card[0][1] == 'A') {
		for (int i = 1; i < 5; ++i) {
			if (card[i][1] == 'T') {
				check[0]++;
			}
			else if (card[i][1] == 'J') {
				check[1]++;
			}
			else if (card[i][1] == 'K') {
				check[2]++;
			}
			else if (card[i][1] == 'Q') {
				check[3]++;
			}
		}
	}
	if (check[0] && check[1] && check[2] && check[3])
		return true;
	return false;
}

int solve() {
	if ((card[0][0] == card[1][0]) && (card[1][0] == card[2][0]) &&
		(card[2][0] == card[3][0]) && (card[3][0] == card[4][0])) {
		if ((number[card[1][1]] == number[card[0][1]] + 1) && (number[card[2][1]] == number[card[1][1]] + 1) &&
			(number[card[3][1]] == number[card[2][1]] + 1) && (number[card[4][1]] == number[card[3][1]] + 1)) {
			return 1;
		}
		else if (royal()) {
			return 1;
		}
		else {
			return 4;
		}
	}
	else if (four_three_card(4)) {
		return 2;
	}
	else if (full_house()) {
		return 3;
	}
	else if ((number[card[1][1]] == number[card[0][1]] + 1) &&	(number[card[2][1]] == number[card[1][1]] + 1) &&
				(number[card[3][1]] == number[card[2][1]] + 1) && (number[card[4][1]] == number[card[3][1]] + 1)) {
		return 5;
	}
	else if ((number[card[2][1]] == number[card[1][1]] + 1) && (number[card[3][1]] == number[card[2][1]] + 1) && 
		(number[card[4][1]] == number[card[3][1]] + 1) && (card[0][1] == 'A') && (card[1][1] != 'A')) {
		return 5;
	}
	else if (four_three_card(3)) {
		return 6;
	}
	else {
		int candi = pair_card();
		if (candi == -1)
			return 9;
		else if (candi == 7)
			return 7;
		else if (candi == 8)
			return 8;
	}
	return 9;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int index = 1;
	number['A'] = index++;
	number['2'] = index++;
	number['3'] = index++;
	number['4'] = index++;
	number['5'] = index++;
	number['6'] = index++;
	number['7'] = index++;
	number['8'] = index++;
	number['9'] = index++;
	number['T'] = index++;
	number['J'] = index++;
	number['Q'] = index++;
	number['K'] = index++;

	ans[1] = "Straight Flush";
	ans[2] = "Four of a Kind";
	ans[3] = "Full House";
	ans[4] = "Flush";
	ans[5] = "Straight";
	ans[6] = "Three of a kind";
	ans[7] = "Two pair";
	ans[8] = "One pair";
	ans[9] = "High card";

	freopen("input.txt", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		card.clear();
		for (int i = 0; i < 5; ++i) {
			string str; cin >> str;
			card.push_back(str);
		}

		sort(card.begin(), card.end(), cmp);

		cout << "#" << t << " " << ans[solve()] << endl;
	}

	return 0;
}
