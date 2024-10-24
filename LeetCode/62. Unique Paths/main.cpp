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
    int uniquePaths(int m, int n) {
        // C(m + n - 2, m)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[1][1] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <=m ;j++) {
                if(i == 1 && j ==1) {
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[n][m];
    }
};