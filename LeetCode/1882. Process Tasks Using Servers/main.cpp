#include<bits/stdc++.h>

using namespace std;

[[gnu::constructor]] void pre(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);} ;


class Solution {
	public:
        pair<int,int>top(set<pair<int,int>>&s) {
            return *s.begin();
        }

        void push(set<pair<int,int>>&s, pair<int,int>p) {
            s.insert(p);
        }

        void pop(set<pair<int,int>>&s) {
            s.erase(s.begin());
        }

		vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
			priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> full; // store {deadline, index of server}
			priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> empty; // store {weight of server, index of server}
            queue<int>q; // store weight of task
            vector<int>ans;

			for(int i = 0; i < servers.size(); i++) {
                empty.push({servers[i], i});
			}

            int t = 0;
            int pos = 0;
            do {
                // produce to queue
                while(pos < tasks.size() && t >= pos) {
                    q.push(tasks[pos++]);
                }

                // fast forward
                if(empty.size() == 0) {
                    t = full.top().first;
                }

                // finish task
                while(full.size() != 0 && t >= full.top().first) {
                    int finishServer = full.top().second;
                    empty.push({servers[finishServer], finishServer});
                    full.pop();
                }

                // consume from queue
                while(empty.size() != 0 && q.size() != 0) {
                    int taskWeight = q.front();
                    q.pop();

                    pair<int,int>firstEmpty = empty.top();
                    empty.pop();

                    full.push( {t + taskWeight, firstEmpty.second});
                    ans.push_back(firstEmpty.second);
                }
                t++;

            }while(q.size() != 0 || pos < tasks.size());

            return ans;


		}
	};