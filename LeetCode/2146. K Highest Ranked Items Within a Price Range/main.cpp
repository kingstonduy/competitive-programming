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
		bool inBoard(int x, int y, int n, int m) {
			return x >= 0 && y >= 0 && x < n && y < m;
		}
	
		bool inRange(int val, vector<int>& pricing) {
			return val <= pricing[1] && val >= pricing[0];
		}
	
		vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
			int n = grid.size();
			int m = grid[0].size();
	
			vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
			// 01 bfs
			deque<pair<int,int>> q;
			vector<vector<int>> dis(n, vector<int>(m,-1));
			
			// ans chua {{distance, price}, {x, y}}
			vector<pair<pair<int,int>, pair<int,int>>> ans;
	
			// check the start position
			int val0 = grid[start[0]][start[1]];
			dis[start[0]][start[1]] = 0;
			q.push_back({start[0], start[1]});
			if(inRange(val0, pricing)) {
				ans.push_back({{0, val0}, {start[0], start[1]}});
			}
	
			int nn = 1e7;
			while(q.size() != 0 ) {
				pair<int, int> now = q.front();
				q.pop_front();
				int x = now.first;
				int y = now.second;
				if(dis[x][y] == nn) {
					break;
					q.clear();
				}
				
				for(int i = 0; i < 4; i++) {
					int xx = x + directions[i].first;
					int yy = y + directions[i].second;
	
					if(inBoard(xx, yy, n, m) && grid[xx][yy] != 0 && dis[xx][yy] == -1) {
						dis[xx][yy] = dis[x][y] + 1;
						q.push_back({xx, yy});
						int val = grid[xx][yy];
						if(inRange(val, pricing)) {
							ans.push_back({{dis[xx][yy], val}, {xx, yy}});
						}
						if(ans.size() >= k) {
							nn = dis[xx][yy];
						}
					}
				}
			}
	
			sort(ans.begin(), ans.end());
			vector<vector<int>> res;
			for(auto i : ans) {
				if(k == 0) {
					break;
				}
				vector<int>temp;
				temp.push_back(i.second.first);
				temp.push_back(i.second.second);
				res.push_back(temp);
				k--;
			}
	
			return res;
		}
	};
	