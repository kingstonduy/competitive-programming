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
    long long numberOfWays(string s) {
        long long ans = 0;

        int cnt0 = 0;
        int cnt1 = 0;

        long long dp1 = 0;
        long long dp0 = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                cnt0++;
                ans += dp1;
                dp0 += cnt1;
            }
            else {
                cnt1++;
                ans += dp0;
                dp1 += cnt0;
            }
        }
        return ans;
    }
};