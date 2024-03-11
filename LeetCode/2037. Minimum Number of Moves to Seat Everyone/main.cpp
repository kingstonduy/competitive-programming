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
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int n = seats.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans += abs(seats[i] - students[i]);
        }

        return ans;
    }
};