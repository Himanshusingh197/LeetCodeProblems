class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.length();
        unordered_map<char, int> mp;

        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }

        int freq = mp.begin()->second;
        for(auto str : mp){
            if(str.second != freq){
                return false;
            }
        }

        return true;
    }
};