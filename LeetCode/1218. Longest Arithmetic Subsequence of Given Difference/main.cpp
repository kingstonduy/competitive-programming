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
    int inf = 1e6;
    int longestSubsequence(vector<int>& arr, int diff) {
       map<int, int>m;
       int ans = 1;
       for(int i = 0 ; i < arr.size(); i++) {
            int num = arr[i];
            if(m[num - diff] == 0 ){
                m[num] = 1;
            } else {
                m[num] = 1 + m[num - diff];
                ans = max(ans, m[num]);
            }
       }
       return ans;
    }
};