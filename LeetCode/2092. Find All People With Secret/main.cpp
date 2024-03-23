#include<bits/stdc++.h>

using namespace std;

// auto fastio=[]()  {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return nullptr;
// }();

class Solution {
public:
    vector<int>par;
    vector<int>sz;

    int find(int a) {
        if(a == par[a]) {
            return a;
        }
        return par[a] = find(par[a]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            if (sz[a] < sz[b]) {
                swap(a, b);
            }
            par[b] = a;
            sz[a] += sz[b];
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        par = vector<int>(n + 10, 0);
        sz = vector<int>(n + 5, 0);


        for(int i = 1; i <= n; i++) {
            par[i] = i;
        }

        unite(0, firstPerson);

        vector<vector<int>>v;
        for(auto i : meetings) {
            vector<int>temp = i;
            reverse(temp.begin(), temp.end());
            v.push_back(temp);
        }
        sort(v.begin(), v.end());

        // for(auto i : v) {
        //     cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
        // }

        int pos = 0;
        set<int>ans;
        ans.insert(0);
        ans.insert(firstPerson);

        while(pos < v.size()) {
            int now = v[pos][0];
            set<int>s;
            bool ok = 0;
            int debug = v[pos][1];
            int debug1 = v[pos][2];
            while(pos < v.size() && v[pos][0] == now) {
                if(find(v[pos][1]) == find(firstPerson) || find(v[pos][2]) == find(firstPerson)) {
                    ok = 1;
                }
                s.insert(v[pos][1]);
                s.insert(v[pos][2]);
                // printf("v[%d][1]=%d, v[%d][2]=%d\n",pos, v[pos][1], pos, v[pos][2]);
                unite(v[pos][1], v[pos][2]);
                pos++;
            }

            for(auto i : s) {
                // printf("i=%d, find[i]=%d, find[target]=%d\n", i, find(i), find(firstPerson));
                if(find(i) != find(firstPerson)) {
                    par[i] = i;
                }
                else {
                    ans.insert(i);
                }
            }

        }

        vector<int>res;
        for(auto i : ans) {
            res.push_back(i);
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 12;
    vector<vector<int>> meetings = {{10,8,6},{9,5,11},{0,5,18},{4,5,13},{11,6,17},{0,11,10},{10,11,7},{5,8,3},{7,6,16},{3,6,10},{3,11,1},{8,3,2},{5,0,7},{3,8,20},{11,0,20},{8,3,4},{1,9,4},{10,7,11},{8,10,18}};
    int firstPerson = 9;
    vector<int>ans = sol.findAllPeople(n, meetings, firstPerson);
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<"\n";
}
