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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = (int)nums1.size(); int n = (int)nums2.size();

        if (m > n) {
            nums1.swap(nums2);
            swap(m, n);
        }

        int iMin = 0, iMax = m, half = (m + n + 1) >> 1;

        while (iMin <= iMax) {
            int i = (iMin + iMax) >> 1;
            int j = half - i;
            if (i < iMax && nums2[j - 1] > nums1[i]) iMin = i + 1;
            else if (i > iMin&& nums1[i - 1] > nums2[j]) iMax = i - 1;
            else {
                int maxLeft = 0;
                if (i == 0) maxLeft = nums2[j - 1];
                else if (j == 0) maxLeft = nums1[i - 1];
                else maxLeft = max(nums1[i - 1], nums2[j - 1]);

                if ((m + n) & 1) return maxLeft;

                int minRight = 0;
                if (i == m) minRight = nums2[j];
                else if (j == n) minRight = nums1[i];
                else minRight = min(nums2[j], nums1[i]);

                return (maxLeft + minRight) / 2.0;
            }
        }

        return 0.0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    Solution s;

    vector<int> nums1 = { 1,2 };
    vector<int> nums2 = { 3,4 };

    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
