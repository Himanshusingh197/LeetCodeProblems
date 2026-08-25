class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        for(int i=1 ; ; i++){
            int multiple = i * k;

            if(mp.find(multiple) == mp.end()){
                return multiple;
            }
        }
    }
};