#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool check(const string& a) {
    int r = 0;
    for (char ch : a) {
        if (ch == '(') ++r;
        else --r;
        if (r < 0) return false;
    }
    return r == 0;
}
string solution(string p) {
    if (p == "") return "";
    if (check(p)) return p;

    int i, t = 0;
    for (i = 0; i < p.size(); ++i) {
        if (p[i] == '(') ++t;
        else --t;
        if (t == 0) break;
    }

    string u = p.substr(0, i + 1);
    string v = p.substr(i + 1);

    if (check(u)) return u + solution(v);

    for (char& ch : u) ch = ch == '(' ? ')' : '(';
    return string("(") + solution(v) + ")" + u.substr(1, u.size() - 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    solution("(()())()");

    return 0;
}
