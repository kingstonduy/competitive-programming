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
    int Cnt(vector<int>&v) {
        int cnt = 0;
        for(auto i : v){
            if(i > 0) {
                cnt++;
            }
        }
        return cnt;
    }

    bool isItPossible(string w1, string w2) {
        vector<int>v1(30, 0);
        vector<int>v2(30, 0);
        int cnt1 = 0;
        int cnt2 = 0;

        for(auto c : w1) {
            int i = c - 'a';
            v1[i]++;
        }
        for(auto c : w2) {
            int i = c - 'a';
            v2[i]++;
        }

        set<pair<char,char>>s;

        for(auto i : w1) {
            for(char c = 'a'; c <= 'z'; c++) {
                if(s.find({i, c}) != s.end())    continue;
                if(v2[c - 'a'] == 0) continue;
                vector<int> temp1 = v1;
                vector<int> temp2 = v2;
                temp1[i - 'a'] --;
                temp1[c - 'a'] ++;

                temp2[i - 'a'] ++;
                temp2[c - 'a'] --;

                if(Cnt(temp1) == Cnt(temp2)) {
                    return true;
                }
                s.insert({i, c});
            }
            
        }

        return false;
    }
};