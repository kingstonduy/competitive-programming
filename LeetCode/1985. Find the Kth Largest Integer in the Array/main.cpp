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

    int convert(string s) {
        int temp = 0;
        for(auto i : s) {
            temp = (temp * 10) + i - '0';
        }

        return temp;
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        vector<int>v;
        for(auto i : nums) {
            v.push_back(stoi(i));
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        // convert in to string

        return to_string(v[k - 1]);
    }
};

int main() {
    Solution sol;
    vector<string>nums = {"3","6","7","10"};
    int k = 4;
    cout<<sol.kthLargestNumber(nums, k);
    return 0;
}