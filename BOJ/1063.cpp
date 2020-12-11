#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define endl '\n'
#define INF 987654321

struct Point {
	int y, x;
};

// ø¿, øﬁ, ¿ß, æ∆∑°, ø¿æ∆∑°, øﬁæ∆∑°, ø¿¿ß, øﬁ¿ß
const int dy[] = { 0,0,-1,1,1,1,-1,-1 };
const int dx[] = { 1,-1,0,0,1,-1,1,-1 };

int board[9][9];
int ord[128];

Point player[2];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int val = 0;
	for (int i = 'A' - 'A'; i <= 'H' - 'A'; ++i) {
		ord[i] = val++;
	}

	map<string, int> pre;
	pre["R"] = 0; pre["L"] = 1; pre["B"] = 2; pre["T"] = 3;
	pre["RT"] = 4; pre["LT"] = 5; pre["RB"] = 6; pre["LB"] = 7;

	string king, stone;
	int N;
	cin >> king;
	int king_y = king[1] - '0';
	int king_x = ord[king[0] - 'A'];

	player[0].y = king_y - 1; player[0].x = king_x;

	cin >> stone;
	int stone_y = stone[1] - '0';
	int stone_x = ord[stone[0] - 'A'];

	player[1].y = stone_y - 1; player[1].x = stone_x;

	cin >> N;
	string input;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		int dir = pre[input];
		king_y = player[0].y; king_x = player[0].x;
		stone_y = player[1].y; stone_x = player[1].x;

		int nky = king_y + dy[dir], nkx = king_x + dx[dir];
		int nsy = stone_y + dy[dir], nsx = stone_x + dx[dir];

		if (nky < 0 || nkx < 0 || nky >= 8 || nkx >= 8) continue;

		if (nky == stone_y && nkx == stone_x) {
			if (nsy < 0 || nsx < 0 || nsy >= 8 || nsx >= 8) continue;
			player[1].y = nsy; player[1].x = nsx;
		}
		player[0].y = nky; player[0].x = nkx;
	}
	
	cout << char(player[0].x + 'A') << player[0].y + 1 << endl;
	cout << char(player[1].x + 'A') << player[1].y + 1 << endl;



	return 0;
}
