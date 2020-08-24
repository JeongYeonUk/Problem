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

int solution(string s)
{
    int size = (int)s.size();
    int answer = size;

    for (int i = 1; i <= (size >> 1); ++i) {
        string ret = "";
        string tmp = s.substr(0, i);
        int count = 1;

        for (int j = i; j <= size; j += i) {
            string check = s.substr(j, i);
            if (tmp == check) {
                count++;
            }
            else {
                if (count == 1) {
                    ret += tmp;
                }
                else {
                    ret += (to_string(count) + tmp);
                }
                tmp = check;
                count = 1;
            }
        }

        // 문자가 남는 것 방지
        if (size / i != 0) {
            ret += s.substr((size / i) * i);
        }
        if (answer > ret.size())
            answer = ret.size();
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    cout << solution("aabbaccc") << endl;

    return 0;
}
