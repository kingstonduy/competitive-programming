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
    string addSpaces(string s, vector<int>& spaces) {
        int pos = 0;
        int n = spaces.size();
        int m = s.size();
        string res;
        for(int i = 0; pos < m;) {
            if(i != n && spaces[i] == pos) {
                res.push_back(' ');
                i++;
            } 
            res.push_back(s[pos++]);
        }
        return res;
    }
};