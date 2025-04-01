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
    vector<vector<int>> groupThePeople(vector<int>& v) {
        auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
        vector<vector<int>>ans;
        int n = v.size();

        vector<vector<int>>g(n + 1, vector<int>());
        for(int i = 0; i < n; i++) {
            int group = v[i];
            
            g[group].push_back(i);

            if(g[group].size()  == group) {
                ans.push_back(g[group]);
                g[group].clear();  // Clear instead of creating a new empty vector
            }
        }

        return ans;
    }
};