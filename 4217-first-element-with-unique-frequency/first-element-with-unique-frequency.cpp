class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        unordered_map<int, int> freqCount;
        for(auto x : mp) {
            freqCount[x.second]++;
        }

        for(int i = 0; i < n; i++) {
            if(freqCount[mp[nums[i]]] == 1) {
                return nums[i];
            }
        }

        return -1;
    }
};