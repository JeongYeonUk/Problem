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

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;

        int len = (int)s.size();

        string ans = "";
        int max = 0;

        bool dp[1001][1001];
        memset(dp, false, sizeof(dp));

        for (int j = 0; j < len; ++j) {
            for (int i = 0; i <= j; ++i) {
                bool judge = s[i] == s[j];

                dp[i][j] = j - i > 2 ? dp[i + 1][j - 1] && judge : judge;

                if (dp[i][j] && j - i + 1 > max) {
                    max = j - i + 1;
                    ans = s.substr(i, max);
                }
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    Solution s;

    cout << s.longestPalindrome("abcdbbfcba") << endl;

    return 0;
}
