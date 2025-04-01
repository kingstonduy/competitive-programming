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
    bool f(vector<int>&num, int k, int p, int l, int r) {
        int cnt = 0;
        for(int i = l ; i <= r && cnt <= k; i++) {
            if(num[i] % p == 0) {
                cnt++;
            }
        }

        return cnt <= k;
    }

    string toString(vector<int>&num, int l, int r) {
        string s;
        for(int i = l; i <= r; i++) {
            s.push_back('a' + num[i]);
        }
        return s;
    }
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans = 1;
        set<string>s;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i; j < nums.size(); j++) {
                if(f(nums, k, p, i, j)) {
                    s.insert(toString(nums, i, j));
                }
            }
        }
        return s.size();
    }
};