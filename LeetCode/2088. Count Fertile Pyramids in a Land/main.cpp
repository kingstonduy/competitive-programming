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
    int normal(vector<vector<int>>&grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> a(n + 5, vector<int>(m + 5, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                a[i][j] = grid[i - 1][j - 1];
            }
        }


        int cnt = 0;

        vector<vector<int>> dp(n + 5, vector<int>(m + 5, 0));
        for(int i = n; i >= 1; i--) {
            for(int j = 1; j <= m; j++) {
                if(a[i][j] && a[i + 1][j]) {
                    dp[i][j] = min(dp[i + 1][j - 1], dp[i + 1][j + 1]) + 1;
                    cnt += dp[i][j] - 1;
                }
                else if(a[i][j]) {
                    dp[i][j] = a[i][j];
                }
            }
        }

        return cnt;
    }

    int revert(vector<vector<int>>&grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>a(n, vector<int>(m, 0));
        int nn = n - 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = grid[nn][j];
            }
            nn--;
        }
        return normal(a);
    }
    
    int countPyramids(vector<vector<int>>& grid) {
        return normal(grid) + revert(grid);
    }
};
