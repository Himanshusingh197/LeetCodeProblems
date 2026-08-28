class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mp;
        int target = n / 4;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }

        for(auto freq : mp){
            if(freq.second > target){
                return freq.first;
            }
        }
        return -1;
    }
};