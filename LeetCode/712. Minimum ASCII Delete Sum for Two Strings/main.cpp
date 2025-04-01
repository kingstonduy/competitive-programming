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

    int compress(int i, int j) {
        return i * 10 + j;
    }

    int minimumDeleteSum(string s1, string s2) {
        auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();

        if(s1.size() < s2.size()) swap(s1, s2);
        int sum1 = 0;
        int sum2 = 0;
        for(auto i:s1) sum1+=i;
        for(auto i:s2) sum2+=i;

        
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 5, vector<int>(m + 5, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if(s1[i - 1] == s2[j - 1]) {
                    int num = s1[i - 1];
                    dp[i][j] = max(dp[i - 1][j - 1] + num, dp[i][j]);
                }
            }
        }
        return sum1 + sum2 - 2 * dp[n][m];
    }
};