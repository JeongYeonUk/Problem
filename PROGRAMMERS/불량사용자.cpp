#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool used[10];
int answer;
set<string> s;

bool is_possible(const string& user, const string& banned)
{
    if (user.size() != banned.size())
        return false;

    for (int i = 0, user_size = (int)user.size(); i < user_size; ++i)
    {
        if (user[i] != banned[i] && banned[i] != '*')
            return false;
    }

    return true;
}

void solve(int idx, const vector<string>& user_id, const vector<string>& banned_id)
{
    if (idx == banned_id.size())
    {
        string tmp;
        for (int i = 0, user_size = (int)user_id.size(); i < user_size; ++i)
        {
            if (used[i])
            {
                tmp += (i + '0');
            }
        }

        if (s.find(tmp) != s.end()) 
            return;

        s.insert(tmp);
        answer++;

        return;
    }

    for (int i = 0, user_size = (int)user_id.size();i < user_size; ++i)
    {
        if (!used[i] && is_possible(user_id[i], banned_id[idx]))
        {
            used[i] = true;
            solve(idx + 1, user_id, banned_id);
            used[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {

    solve(0, user_id, banned_id);

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector<string> banned_id = { "fr*d*", "abc1**" };

    cout << solution(user_id, banned_id);

    return 0;
}
