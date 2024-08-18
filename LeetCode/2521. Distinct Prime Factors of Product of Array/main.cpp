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
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int>primes;
        for(int i = 2; i <= 1000; i++) {
            bool isPrime = true;
            for(int j = 2; j * j <= i ;j ++) {
                if(i % j == 0) {
                    isPrime = false; 
                    break;
                }
            }
            if(isPrime) {
                primes.push_back(i);
            }
        }
    
        set<int>s;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < primes.size() && primes[j] <= nums[i]; j++) {
                if(nums[i] % primes[j] == 0) {
                    s.insert(primes[j]);
                }
            }
        }

        return s.size();

        return 1;
    }
};