
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        vector<int> count(k, 0);

        set<int> available;

        // {finishing time, server index}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        // Initially, all servers are available
        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        // Process each request
        for(int i = 0; i < arrival.size(); i++) {

            // Release servers that have finished
            while(!busy.empty() &&
                  busy.top().first <= arrival[i]) {

                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            // If all servers are busy, drop request
            if(available.empty()) {
                continue;
            }

            // Preferred server
            int preferred = i % k;

            // Find first available server >= preferred
            auto it = available.lower_bound(preferred);

            // If not found, wrap around
            if(it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request
            available.erase(it);

            count[server]++;

            // Store server's finishing time
            busy.push({
                (long long)arrival[i] + load[i],
                server
            });
        }

        // Find maximum requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        // Return all busiest servers
        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
