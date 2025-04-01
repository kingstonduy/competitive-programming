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
    bool f(vector<int>& v, int k, int num) {
        int cnt = 0;
        int take = 0 ;
        for(int i = 0; i < v.size() && cnt < k; i++) {
            if(v[i] <= num) {
                if(take == 0) {
                    take = 1;
                    cnt++;
                } else {
                    take = 0;
                }
            } else {
                take = 0;
            }
        }
        return cnt == k;
    }
    int minCapability(vector<int>& v, int k) {
        vector<int>nums;
        for (auto i : v) {
            nums.push_back(i);
        }

        sort(nums.begin(), nums.end());
        int ans = nums[nums.size() - 1];

        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int num = nums[mid];
            if(f(v, k, num)) {
                ans = min(ans, num);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};