class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> block;
        for(int i=0; i<n; i++){
            if(i == 0 || nums[i] != nums[i-1]){
                block[nums[i]]++;
            }
        }
        int count = 0;
        for(auto num : block){
            if(num.second == 1){
                count++;
            }
        }

        return count;
    }
};