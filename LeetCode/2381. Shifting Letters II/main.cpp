#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n  = s.size();
        vector<int> cnt(n, 0);

        for(auto i : shifts) {
            cnt[i[0]] += (i[2] ==  1) ? 1 : -1;
            if(i[1] + 1 < n) cnt[i[1] + 1] -= (i[2] == 1) ? 1 : -1;
        }

        int temp = 0;

        for(int i = 0; i < n; i++) {
            temp += cnt[i];
            if(temp < 0) {
                temp = -(abs(temp) %26);
            } else if(temp > 0) {
                temp = (abs(temp) % 26);
            }
            int c = s[i] + temp;
            if(c < 'a') {
                c = 'z' - ('a' - c) + 1;
            }
            else if(c > 'z') {
                c = 'a' + (c - 'z') - 1;
            }
            s[i] = c;
        }
        return s;
    }
};

int main() {
    string s = "ksztajnymer";
    vector<vector<int>> shifts = {{4,9,1},{2,5,1},{7,9,0},{6,10,0},{1,7,1},{0,7,1},{0,3,0},{3,3,1},{7,9,0},{7,7,0},{6,7,0},{7,9,0},{3,9,0},{10,10,1},{8,9,0},{6,9,1},{1,2,1},{3,9,0},{8,10,1},{4,7,1},{9,10,1},{8,9,0},{5,8,0},{8,9,1},{0,7,1},{2,2,1},{8,8,1},{3,7,0},{1,10,1},{9,9,1},{4,9,0},{5,6,1},{7,8,1},{8,9,0},{7,7,1},{9,9,1}};
    Solution sol;
    cout<<sol.shiftingLetters(s, shifts);
}
