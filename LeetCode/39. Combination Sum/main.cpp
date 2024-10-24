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
    vector<vector<int>> combinationSum(vector<int>& v, int sum) {
        sort(v.begin(), v.end());
        vector<vector<vector<int>>>dp(sum + 1, vector<vector<int>>(0, vector<int>()));
        for(auto i : v) {
            for(int j = v[0]; j <= sum; j++) {
                if(j - i == 0) {
                    vector<int> temp = vector<int>(1, i);
                    dp[j].push_back(temp);
                }
                else if (j - i > 0) {
                    vector<vector<int>>pre = dp[j - i];
                    for(int x = 0; x < pre.size(); x++) {
                        pre[x].push_back(i);
                    }

                    for(int x = 0; x < pre.size(); x++) {
                        dp[j].push_back(pre[x]);
                    }
                }
            }
        }
        return dp[sum];
    }
};