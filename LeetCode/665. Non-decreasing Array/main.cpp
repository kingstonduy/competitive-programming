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

    bool check(vector<int>nums) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }

    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) {
            return true;
        }

        if(check(nums)) {
            return true;
        }
        
        vector<int>checkL(n, 0);
        checkL[0] = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] >= nums[i - 1]) {
                checkL[i] = checkL[i - 1];
            }
        }

        vector<int>checkR(n, 0);
        checkR[n - 1] = 1;
        for(int i = n - 2 ; i >= 0; i--) {
            if(nums[i] <= nums[i + 1]) {
                checkR[i] = checkR[i + 1];
            }
        }


        

        // replace thang index 0
        if(checkR[1] == 1) {
            return true;
        }

        // replace thang index n - 1
        if(checkL[n - 2] == 1) {
            return true;
        }

        for(int i =  1; i <= n - 2; i++) {
            // replace thang i dc ko ?
            if(checkL[i - 1] == 1 && checkR[i + 1] == 1 && nums[i - 1] <= nums[i + 1]) {
                return true;
            }
        }

        return false;
    }
};