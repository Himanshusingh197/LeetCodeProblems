class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = magazine.length();
        int n = ransomNote.length();

        unordered_map<char, int> mp;
        for(int i=0; i<m; i++){
            mp[magazine[i]]++;
        }

        for(int i=0; i<n; i++){
            if(mp[ransomNote[i]] == 0){
                return false;
            }
            mp[ransomNote[i]]--;
        }
        return true;
    }
};