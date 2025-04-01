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
    int minSetSize(vector<int>& arr) {
        map<int,int>m;
        int cnt = 0;
        int sum = 0;
        for(auto i :arr) {
            m[i]++;
        }

        vector<int>v;
        for(auto i : m) {
            v.push_back(i.second);
        }
        
        sort(v.begin(),v.end());
        
        for(int i = v.size() - 1; i >= 0 && sum < arr.size() / 2; i--) {
            cnt++;
            sum += v[i];
        }
        return cnt;
    }
};