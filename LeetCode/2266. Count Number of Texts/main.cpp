#include<bits/stdc++.h>

using namespace std;

auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();



class Solution {
public:
   
 
    int countTexts(string s) {
        long long int mod = 1e9 + 7;
        int n = s.size();
        long long int dp[n + 1][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = dp[0][1] = 1;
        dp[1][0] = dp[1][1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int x = 1; x <= 3 && i - x >= 0; x++) {
                    dp[i][0] = (dp[i][0] + dp[i - x][0]) % mod;
                    dp[i][1] = (dp[i][1] + dp[i - x][1]) % mod;
            }
            if(i - 4 >= 0) {
                dp[i][1] = (dp[i][1] + dp[i - 4][1]) % mod;
            }
        }

        
        int cnt = 1;
        long long int ans = 1;
        for(int i = 1;i < n; i++) {
            if(s[i] == s[i - 1]) {
                cnt++;
            } else {
                if(s[i - 1] == '7' || s[i - 1] == '9') {
                    ans = (ans * dp[cnt][1]) % mod;
                } else {
                    ans = (ans * dp[cnt][0]) % mod;
                }
                cnt = 1;
            }

        }
        cout<<ans<<" "<<dp[cnt][0]<<" "<<dp[cnt][1];
        if(s[n - 1] == '7' || s[n - 1] == '9') {
            ans = (ans * dp[cnt][1]) % mod;
        } else {
            ans = (ans * dp[cnt][0]) % mod;
        }
        return ans;
        
    }
};