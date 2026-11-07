
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        // {weight, index}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> freeServers;

        // {freeTime, weight, index}
        priority_queue<tuple<long long,int,int>,
                       vector<tuple<long long,int,int>>,
                       greater<tuple<long long,int,int>>> busyServers;

        for(int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans(m);

        long long time = 0;

        for(int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            // Release completed servers
            while(!busyServers.empty() &&
                  get<0>(busyServers.top()) <= time) {

                auto [freeTime, weight, index] = busyServers.top();
                busyServers.pop();

                freeServers.push({weight, index});
            }

            // If no server is free, jump to earliest free time
            if(freeServers.empty()) {

                time = get<0>(busyServers.top());

                while(!busyServers.empty() &&
                      get<0>(busyServers.top()) <= time) {

                    auto [freeTime, weight, index] = busyServers.top();
                    busyServers.pop();

                    freeServers.push({weight, index});
                }
            }

            auto [weight, index] = freeServers.top();
            freeServers.pop();

            ans[i] = index;

            busyServers.push({
                time + tasks[i],
                weight,
                index
            });
        }

        return ans;
    }
};
