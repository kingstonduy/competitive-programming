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
		int maximalSquare(vector<vector<char>>& a) {
			int n = a.size();
			int m = a[0].size();
	
			int ans = 0;
	
			vector<vector<int>>dp(n, vector<int>(m, 0));
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					dp[i][j] = (a[i][j] == '1');
					if(i > 0 && j > 0 && a[i][j] == '1') {
						dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
					}
					ans = max(ans, dp[i][j]);
				}
			}
			return ans * ans;
		}
};