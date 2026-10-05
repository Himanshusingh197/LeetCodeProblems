class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for(auto &p : mp) {
            vector<int>& indices = p.second;

            long long sum = 0;

            for(int index : indices) {
                sum += index;
            }

            long long leftSum = 0;

            for(int i = 0; i < indices.size(); i++) {
                long long current = indices[i];
                sum -= current;

                long long leftCount = i;
                long long rightCount = indices.size() - i - 1;

                long long leftDistance =
                    current * leftCount - leftSum;

                long long rightDistance =
                    sum - current * rightCount;

                ans[current] = leftDistance + rightDistance;

                leftSum += current;
            }
        }

        return ans;
    }
};