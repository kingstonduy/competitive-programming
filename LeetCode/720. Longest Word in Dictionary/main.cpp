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
    string longestWord(vector<string>& words) {
        // check impossible
        bool check = false;
        for(auto i: words) {
            if(i.size() == 1) {
                check = true;
                break;
            }
        }
        if (!check) {
            return "";
        }
        sort(words.begin(), words.end());
        string res = words[0];

        map<string,int>m;
        for(auto w : words) {
            m[w] = 2;
        }
        for(auto w : words) {
            bool ok = 1;
            for(int i = 0; i <= w.size() -2 && ok; i++) {
                string temp = subString(w, 0, i);
                if(m[temp] != 2) {
                    ok = 0;
                }
            }
            if(ok) {
                if (res.size() == w.size()) {
                    res = min(res, w);
                } else if(res.size() < w.size()) {
                    res = w;
                }
            }
        }
        return res;
    }

    string subString(string s, int l, int r) {
        string res = "";
        for(int i = l; i <= r; i++) {
            res+= s[i];
        }
        return res;
    }
};