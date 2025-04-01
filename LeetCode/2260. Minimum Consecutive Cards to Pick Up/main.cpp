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
    int minimumCardPickup(vector<int>& cards) {
        map<int,int>m;
        int ans = -1;
        for(int i = 1; i <= cards.size(); i++) {
            int card = cards[i - 1];
            if(m[card] != 0) {
                if(ans == -1) {
                    ans = (i - m[card] + 1);
                } else {
                    ans = min(ans, i - m[card] + 1);
                }
            }
            m[card] = i;
        }
        return ans;
    }
};