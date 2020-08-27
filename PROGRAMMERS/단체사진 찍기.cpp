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

int solution(int n, vector<string> data)
{
	int friends[256] = { 0, };
	friends['A'] = 1; friends['C'] = 2; friends['F'] = 3; friends['J'] = 4;
	friends['M'] = 5; friends['N'] = 6; friends['R'] = 7; friends['T'] = 8;

	vector<int> line = { 1,2,3,4,5,6,7,8 };
	int answer = 0;
	do {
		bool flag = true;
		for (int i = 0, d_size = (int)data.size(); i < d_size; ++i) {
			int a = friends[data[i][0]];
			int b = friends[data[i][2]];
			int num = (data[i][4] - '0');
			num++;

			int a_idx = 0, b_idx = 0;
			for (int j = 0, l_size = (int)line.size(); j < l_size; ++j) {
				if (a == line[j]) a_idx = j;
				if (b == line[j]) b_idx = j;
			}

			if (data[i][3] == '=') {
				if (!(abs(a_idx - b_idx) == num)) {
					flag = false;
					break;
				}
			}
			else if (data[i][3] == '>') {
				if (!(abs(a_idx - b_idx) > num)) {
					flag = false;
					break;
				}
			}
			else if (data[i][3] == '<') {
				if (!(abs(a_idx - b_idx) < num)) {
					flag = false;
					break;
				}
			}
		}
		if (flag) answer++;
	} while (next_permutation(line.begin(), line.end()));

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int answer = solution(2, { "N~F=0","R~T>2" });
	cout << answer << endl;

	return 0;
}
