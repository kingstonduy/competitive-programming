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
    long long mostPoints(vector<vector<int>>& q) {
        auto fastio = []() {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();

        int n = q.size();
        vector<long long> dp(n + 1, 0);
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            int r = i + q[i][1] + 1;
            dp[i] = q[i][0];
            if (i + 1 < n)
                dp[i] = max(dp[i], dp[i + 1]);
            if (r < n) {
                dp[i] = max(dp[i], q[i][0] + dp[r]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<vector<int>>nums = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    cout<<sol.mostPoints(nums)<<"\n";
    return 0;
}
