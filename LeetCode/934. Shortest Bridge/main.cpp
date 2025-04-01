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
    vector<vector<bool>> visited;

    int n, m;

    bool inBoard(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }

    void dfs(int x, int y, vector<vector<int>>& a) {
        if (visited[x][y]) {
            return;
        }

        visited[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (inBoard(xx, yy) && !visited[xx][yy] && a[xx][yy] == 1) {
                dfs(xx, yy, a);
            }
        }
    }

    int cal(pair<int, int> p1, pair<int, int> p2) {
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    }

    vector<int> dx = {0, -1, 1, 0};
    vector<int> dy = {-1, 0, 0, 1};

    int shortestBridge(vector<vector<int>>& a) {
        visited = vector<vector<bool>>(105, vector<bool>(105, false));
        set<pair<int, int>> s1;
        set<pair<int, int>> s2;

        n = a.size();
        m = a[0].size();

        pair<int,int>p1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    p1 = {i, j};
                    break;
                }
            }
        }

        dfs(p1.first, p1.second, a);

        vector<pair<int, int>> v1, v2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] && visited[i][j]) {
                    v1.push_back({i, j});
                } else if (a[i][j] && !visited[i][j]) {
                    v2.push_back({i, j});
                }
            }
        }

        for (auto i : v1) {
            cout << i.first << "," << i.second << " ";
        }
        cout << "\n";
        for (auto i : v2) {
            cout << i.first << i.second << " ";
        }

        int ans = 1000000;

        for (auto i : v1) {
            for (auto j : v2) {
                ans = min(ans, cal(i, j));
            }
        }

        return ans - 1;
    }
};