class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        vector<int> ans;
        if(m != n)
            return false;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] != goal[i]){
                ans.push_back(i);
            }
        }

        if(ans.size() == 2){
            int i = ans[0];
            int j = ans[1];

            if(s[i] == goal[j] && s[j] == goal[i]){
                return true;
            }
        }

        vector<int> freq(26, 0);
        if(ans.size() == 0){
            for(char ch : s){
                freq[ch - 'a']++;

                if(freq[ch - 'a'] == 2)
                    return true;
            }
        }

        return false;
    }
};