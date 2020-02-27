#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

struct CHECK {
	string one;
	string two;
	string three;

	const bool operator==(const CHECK& rhs) const {
		return one == rhs.one && two == rhs.two && three == rhs.three;
	}

	const bool operator<(const CHECK& rhs) const {
		if (one == rhs.one) {
			if (two == rhs.two)
				return three < rhs.three;
			return two < rhs.two;
		}
		return one < rhs.one;
	}
};

struct INFO {
	int cnt;
	string one;
	string two;
	string three;
};
INFO start;
set<CHECK> visit;

bool isOk(const string& str, char ch) {
	for (int i = 0; i < (int)str.length(); ++i) {
		if (str[i] != ch)
			return false;
	}
	return true;
}

int solve() {
	queue<INFO> q;
	q.push(start);
	string check = start.one + start.two + start.three;
	visit.insert({start.one, start.two, start.three});

	while (!q.empty()) {
		int cnt = q.front().cnt; 
		string one = q.front().one; string two = q.front().two; string three = q.front().three;
		q.pop();
		if (isOk(one, 'A') && isOk(two, 'B') && isOk(three, 'C')) {
			return cnt;
		}	

		// 1 to 3 or 1 to 2
		if (!one.empty()) {
			string none = one.substr(0, one.size() - 1);
			string ntwo = two + one.back();
			string nthree = three + one.back();
			if (visit.find({ none, two ,nthree }) == visit.end()) {
				visit.insert({ none, two ,nthree });
				q.push({ cnt + 1, none, two, nthree });
			}

			if (visit.find({ none , ntwo , three }) == visit.end()) {
				visit.insert({ none , ntwo , three });
				q.push({ cnt + 1, none, ntwo, three });
			}
		}

		// 2 to 3 or 2 to 1
		if (!two.empty()) {
			string none = one + two.back();
			string ntwo = two.substr(0, two.size() - 1);
			string nthree = three + two.back();
			if (visit.find({ one , ntwo , nthree }) == visit.end()) {
				visit.insert({ one , ntwo , nthree });
				q.push({ cnt + 1, one, ntwo, nthree });
			}

			if (visit.find({ none , ntwo , three }) == visit.end()) {
				visit.insert({ none , ntwo , three });
				q.push({ cnt + 1, none, ntwo, three });
			}
		}

		// 3 to 1 or 3 to 2
		if (!three.empty()) {
			string none = one + three.back();
			string ntwo = two + three.back();
			string nthree = three.substr(0, three.size() - 1);
			if (visit.find({ none , two , nthree }) == visit.end()) {
				visit.insert({ none , two , nthree });
				q.push({ cnt + 1, none, two, nthree });
			}

			if (visit.find({ one , ntwo , nthree }) == visit.end()) {
				visit.insert({ one , ntwo , nthree });
				q.push({ cnt + 1, one, ntwo, nthree });
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int len;
	for (int i = 0; i < 3; ++i) {
		cin >> len;
		if (len == 0)
			continue;
		string str;
		cin >> str;
		if (i == 0) {
			start.one = str;
		}
		else if (i == 1) {
			start.two = str;
		}
		else if (i == 2) {
			start.three = str;
		}
	}

	
	cout << solve() << endl;

	return 0;
}
