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
    int findMaxLength(vector<int>& nums) {
        map<int,int>m;

        int sum = 0;
        int ans = 0;

        for(int i = 1; i <= nums.size(); i++) {
            if(nums[i - 1] == 1) {
                sum++;
            } else {
                sum--;
            }

            // printf("i=%d, sum=%d, m[%d]=%d\n", i, sum, sum, m[sum]);

            if(sum == 0) {
                ans = max(ans, i);
            } else if(m[sum] == 0) {
                m[sum] = i;
            }
            else {
                // printf("PINGO i=%d, sum=%d, m[%d]=%d\n", i, sum, sum, m[sum]);
                ans = max(ans, i - m[sum]);
            }
        } 

        return ans;
    }
};

int main() {
    vector<int> nums = {0,0,1,0,0,0,1,1};
    Solution sol;
    cout<<sol.findMaxLength(nums)<<"\n";

    return 0;
}