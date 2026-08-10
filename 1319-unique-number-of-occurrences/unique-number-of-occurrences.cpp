class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        unordered_map<int, int> freqMap;
        for(auto x : mp) {

            int frequency = x.second;
            if(freqMap[frequency] > 0) {
                return false;
            }
            freqMap[frequency]++;
        }
        return true;
    }
};