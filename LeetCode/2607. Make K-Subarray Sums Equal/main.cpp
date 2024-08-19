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
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        k = __gcd(n, k);
        long long res = 0;
        vector<bool>check(n, false);
        for(int i = 0; i < n; i ++) {
            if(check[i]) {
                continue;
            }
            vector<int>v;
            for(int j = i; j < n; j+=k) {
                check[j] = 1;
                v.push_back(arr[j]);
            }
            sort(v.begin(), v.end());
            int med = v[v.size() / 2];
            for(auto i : v) {
                res += abs(i - med);
            }
        }

        return res;
    }
};


int main() {
    Solution sol;
    vector<int>nums = {2,5,5,7};
    int k = 3;
    cout<<sol.makeSubKSumEqual(nums, k)<<"\n";
    return 0;
}
