class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;

        for (int x : nums) {
            ans.push_back(x);

            int i = ans.size() - 1;

            while (i > 0 && ans[i] == ans[i - 1]) {
                ans[i - 1] *= 2;
                ans.erase(ans.begin() + i);
                i--;
            }
        }

        return ans;
    }
};