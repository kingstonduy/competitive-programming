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
    
    bool startWithVowel(string s) {
        int n = s.size() - 1;
        return (s[0] == 'u' || s[0] == 'e' || s[0] == 'o' || s[0] == 'a' || s[0] == 'i') &&
        (s[n] == 'u' || s[n] == 'e' || s[n] == 'o' || s[n] == 'a' || s[n] == 'i');
    }

    int query(vector<int>&v, int l, int r) {
        if (l == 0) {
            return v[r];
        }
        return v[r] - v[l - 1];
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>pre(n + 1, 0);
        for(int i = 0; i < n; i++) {
            string w = words[i];
            if (i != 0) {
                pre[i] = pre[i -1];
            }
            if(startWithVowel(w)){
                pre[i]++;
            } 
        }

        vector<int>ans;
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(query(pre, queries[i][0], queries[i][1]));
        }
        return ans;
    }
};