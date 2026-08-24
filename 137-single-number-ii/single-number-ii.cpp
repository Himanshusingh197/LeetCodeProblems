class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int>mp;
        int i = 0;
        for(i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        for(i=0; i<n; i++){
            if(mp[nums[i]] == 1){
                return nums[i];
            }
        }

        return -1;
    }
};