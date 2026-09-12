class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;

        if (n % k != 0) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int current = 0;
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]] == 0)
                continue;

            for (int j = 0; j < k; j++) {
                int current = nums[i] + j;

                if (mp[current] == 0)
                    return false;

                mp[current]--;
            }
        }

        return true;
    }
};