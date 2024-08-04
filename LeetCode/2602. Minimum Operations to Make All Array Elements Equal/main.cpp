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
    // how many number in nums that is <= x
    int binSearch(vector<int>& nums, int n,int x) {
        int l = 1;
        int r = n;
        int ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] > x) {
                r = mid - 1;
            } else {
                ans = max(mid, ans);
                l = mid + 1;
            }
        }

        return ans;
    }

    int cal(int l, int r, vector<long long> &fre) {
        return fre[r] - fre[l - 1];
    }

    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int sum = 0;
        vector<long long>fre(n + 1, 0);
        vector<long long>ans;
        vector<int>a(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            a[i] = nums[i - 1];
            sum += a[i];
        }
        sort(a.begin(), a.end());

        for(int i = 1; i <= n; i++) {
            fre[i] = fre[i - 1] + a[i];
        }

        
        for(int i = 0; i < queries.size(); i++) {
            int pos = binSearch(a, n, queries[i]);
            cout<<"DEBUG "<<pos<<"\n";
            ans.push_back(pos * queries[i] - cal(1, pos, fre) + cal(pos, n, fre) - queries[i] * (n - pos));
        }

        return ans;
    }
};

int main() {
    vector<int>nums = {3,1,6,8};
    vector<int>queries = {1, 5};
    Solution sol;
    
    vector<long long> ans = sol.minOperations(nums, queries);

    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}
