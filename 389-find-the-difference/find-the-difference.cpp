class Solution {
public:
    char findTheDifference(string s, string t) {
        int m = s.size();
        int n = t.size();

        unordered_map<char, int> mp;

        for(int i=0; i<m; i++){
            mp[s[i]]++;
        }

        for(int i=0; i<n; i++){
            if(mp[t[i]] == 0){
                return t[i];
            }

            mp[t[i]]--;
        }
        return ' ';
    }
};