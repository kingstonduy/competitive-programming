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
    int pivotInteger(int n) {
        if(n == 1) {
            return n;
        }
        vector<long long int>pre(2005, 0);
        for(int i = 1; i <= 2000; i++) {
            pre[i] = pre[i - 1] + i;
        }

        for(int i = 2; i <= n; i++) {
            if(pre[i] == (pre[n] - pre[i - 1])) {
                return i;
            }
        }
        return -1;
    }
};