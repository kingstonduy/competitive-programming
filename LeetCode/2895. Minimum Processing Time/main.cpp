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
    int minProcessingTime(vector<int>& p, vector<int>& t) {
        sort(p.begin(), p.end());
        sort(t.begin(),t.end());
        vector<int>check(p.size() +1, 4);
        int ans = 0;
        for(int i = 0; i < p.size(); i++) {
            int mx = t.back();
            for(int j = 1; j <= 4; j++) {
                t.pop_back();
            }
            ans=max(ans, p[i] + mx);
        }
        return ans;
    }
};