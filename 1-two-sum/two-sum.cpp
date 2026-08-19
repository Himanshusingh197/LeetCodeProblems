class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            int targetSubs = target - nums[i];

            if(mp.find(targetSubs) != mp.end()){
                return {mp[targetSubs], i};
            }
            mp[nums[i]] = i;
        }

        return {};
    }
};