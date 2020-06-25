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

// nums �迭���� target�� ���� �� �ִ� �ε��� 2���� ��ȯ�϶�
vector<int> twoSum(vector<int> nums, int target)
{
    vector<int> answer;

    int size = (int)nums.size();

    bool theEnd = false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) continue;
            if (nums[i] == nums[j]) continue;
            if (nums[i] + nums[j] == target) {
                answer.push_back(i);
                answer.push_back(j);
                theEnd = true;
                break;
            }
        }
        if (theEnd) break;
    }
    return answer;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    vector<int> answer = twoSum({ 2,7,11,15 }, 9);

    for (int ans : answer) {
        cout << ans << ",";
    }

    return 0;
}
