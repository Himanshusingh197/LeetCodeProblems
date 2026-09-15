class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        vector<int> ans;
        for(auto x : mp){
            if(x.second == 1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};