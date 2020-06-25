#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class Solution {
public:
    unordered_map<char, int> hash;
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        int i = 0;
        int j = 0;
        int ret = 0;
        int temp = 0;

        while (j < (int)s.size()) {
            char ch = s[j];
            if (hash.find(ch) == hash.end() || hash[ch] < i) {
                hash[ch] = j;
                temp++;
            }
            else {
                i = hash[ch] + 1;
                temp = j - i + 1;
                hash[ch] = j;
            }
            ret = max(ret, temp);
            j++;
        }

        return ret;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    Solution* s = new Solution();
    int ans = s->lengthOfLongestSubstring("pwwkew");
    cout << ans << endl;
    return 0;
}
