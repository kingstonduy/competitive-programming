#include<bits/stdc++.h>

using namespace std;

auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>odd, even;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(i & 1) {
                odd.push_back(nums[i]);
            } else {
                even.push_back(nums[i]);
            }
        }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        reverse(odd.begin(), odd.end());

        int pos1 = 0;
        int pos2 = 0;

        for(int i = 0 ; i < n; i++) {
            if(i & 1) {
                nums[i] = odd[pos1++];
            } else {
                nums[i] = even[pos2++];
            }
        }

        return nums;
    }
};