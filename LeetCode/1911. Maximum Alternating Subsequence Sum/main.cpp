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
    /* 
    at i 
        + not choose a[i] 
            -> best[i] = best[i - 1];
            -> worst[i] = worst[i - 1]
        + choose a[i] 
            -> best[i] = a[i] - worst[i - 1]
            -> worst[i] = a[i] - best[i - 1]

    */
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long>best(n + 5, 0);
        vector<long long>worst(n + 5, 0);
        for(int i = 1; i <= n; i++) {
            long long num = nums[i - 1];
            best[i] = max(best[i - 1], num - worst[i - 1]);
            worst[i] = min(worst[i - 1], num - best[i - 1]);
        }
        return best[n];
    }
};

int main() {
    Solution sol;
    vector<int>nums = {4, 2, 5, 3};
    cout<<sol.maxAlternatingSum(nums)<<"\n";
}