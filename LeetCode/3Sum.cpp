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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;

        if (nums.size() < 3) return answer;

        for (int i = 0, size = (int)nums.size(); i < size; ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                int j = i + 1;
                int k = size - 1;

                while (j < k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        answer.push_back(temp);

                        ++j;
                        --k;

                        while (j < k && nums[j] == nums[j - 1]) ++j;
                        while (j < k && nums[k] == nums[k + 1]) --k;

                    }
                    else if (nums[i] + nums[j] + nums[k] < 0) {
                        ++j;
                    }
                    else {
                        --k;
                    }
                }
            }
        }
        return answer;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    Solution s;
    
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };

    vector<vector<int>> answer = s.threeSum(nums);

    for (auto a : answer) {
        for (auto b : a) {
            cout << b << ",";
        }
        cout << endl;
    }

    return 0;
}
