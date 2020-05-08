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

vector<int> solution(string s)
{
    // preprocess
    vector<int> vec;
    for (int i = 1, s_size = (int)s.size(); i < s_size - 1; ++i)
    {
        int sum = 0;
        if (s[i] == '{')
        {
            int idx = i + 1;
            for (int j = idx + 1; j < s_size; ++j)
            {
                if (s[j] == ',')
                {
                    sum += (stoi(s.substr(idx, j - idx)));
                    idx = j + 1;
                }

                if (s[j] == '}')
                {
                    sum += (stoi(s.substr(idx, j - idx)));
                    idx = j + 1;
                    break;
                }
            }
            vec.push_back(sum);
        }
    }

    vector<int> answer;
    sort(vec.begin(), vec.end());
    answer.push_back(vec[0]);

    for (int i = 1, vec_size = (int)vec.size(); i < vec_size; ++i)
    {
        answer.push_back(vec[i] - vec[i - 1]);
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    for (auto out : solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
    {
        cout << out << ', ';
    }

    return 0;
}
