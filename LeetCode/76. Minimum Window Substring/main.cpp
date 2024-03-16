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
    int n;
    int m;
    vector<vector<int>>pre;
    vector<int>condition;

    int hash(char c) {
        if(c >= 'A' && c <= 'Z') {
            return c - 'A' + 26;
        }
        return c - 'a';
    }

    bool check(int l, int r) {
        for(int i = 0; i < 60 ; i++) {
            if((pre[r][i] - pre[l - 1][i]) < condition[i]) {
                return false;
            }
        }
        return true;
    }

    pair<bool,int> binSearch(int pos) {
        int l = pos;
        int r = n;
        int ans = 1e8;

        while(l <= r) {
            int mid = (l + r) / 2;
            bool ok = check(pos, mid);
            if(ok) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if(ans == 1e8) {
            return {false, -1};
        } else {
            return {true, ans};
        }
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        s = " " + s;
        t = " " + t;
        
        pre = vector<vector<int>>(n + 1, vector<int>(60, 0)); // store prefix of s
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 60; j++) {
                pre[i][j] = pre[i - 1][j];
                int temp = hash(s[i]);
                if(hash(s[i]) == j) {
                    pre[i][j]++;
                }
                // cout<<pre[i][j]<<" ";
            }
            // cout<<"\n";
        }

        condition = vector<int>(60, 0);
        for(int i = 1; i <= m; i++) {
            condition[hash(t[i])]++;
        }

        if(check(1, n) == false) {
            return "";
        }

        pair<int,int> ans = {1, n};
        for(int i = 1; i <= n; i++) {
            auto it = binSearch(i);
            if(it.first == true && (ans.second - ans.first) >  (it.second - i)) {
                ans = {i, it.second};
            }
        }

        string res;
        for(int i = ans.first; i <= ans.second; i++) {
            res.push_back(s[i]);
        }
        return res;
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    cout<<sol.minWindow(s, t)<<"\n";

    return 0;
}
