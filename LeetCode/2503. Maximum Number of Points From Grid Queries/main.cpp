#include<bits/stdc++.h>
#include <vector>


using namespace std;

auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    bool inBoard(pair<int, int> now, int n, int m) {
        return now.first >= 0 && now.first < n && now.second >= 0 &&
               now.second < m;
    }

    priority_queue<pair<int, pair<int, int>>> rem;
    const int maxn = 1005;
    vector<vector<bool>> visited;
    int ans = 0;

    void bfs(vector<vector<int>>& a, int val) {
        int n = a.size();
        int m = a[0].size();
        queue<pair<int, int>> q;

        while (rem.size()) {
            int currentVal = -rem.top().first;
            if (val > currentVal) {
                q.push(rem.top().second);
                rem.pop();
            } else {
                break;
            }
        }
        while (q.size()) {
            pair<int, int> now = q.front();
            q.pop();
            if (visited[now.first][now.second])
                continue;
            ans++;
            visited[now.first][now.second] = 1;
            for (int i = 0; i < 4; i++) {
                int xx = now.first + dx[i];
                int yy = now.second + dy[i];
                if (inBoard({xx, yy}, n, m) && !visited[xx][yy]) {
                    if (val > a[xx][yy]) {
                        q.push({xx, yy});
                    } else {
                        rem.push({-a[xx][yy], {xx, yy}});
                    }
                }
            }
        }
    }

    vector<int> maxPoints(vector<vector<int>>& a, vector<int>& qq) {
        auto fastio = []() {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();

        vector<int> res(qq.size());
        
        visited = vector<vector<bool>>(maxn, vector<bool>(maxn, false));
        vector<pair<int, int>> queries;

        for (int i = 0; i < qq.size(); i++) {
            queries.push_back({qq[i], i});
        }
        sort(queries.begin(), queries.end());

        rem.push({-a[0][0], {0, 0}});
        for (int i = 0; i < queries.size(); i++) {
            bfs(a, queries[i].first);
            res[queries[i].second] = ans;
        }

        return res;
    }
};