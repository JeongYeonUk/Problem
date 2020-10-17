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

vector<int> split(const string& s)
{
	vector<int> candi;
	string candi_string = "";
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == ' ') {
			candi.push_back(stoi(candi_string));
			candi_string = "";
			continue;
		}
		candi_string += s[i];
	}

	if (!candi_string.empty()) {
		candi.push_back(stoi(candi_string));
	}

	return candi;
}

string solution(string s)
{
	
	vector<int> split_string = split(s);
	
	int maxi = *max_element(split_string.begin(), split_string.end());
	int mini = *min_element(split_string.begin(), split_string.end());

	string answer = "";
	answer += to_string(mini);
	answer += ' ';
	answer += to_string(maxi);

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution("1 2 3 4") << endl;

	return 0;
}
