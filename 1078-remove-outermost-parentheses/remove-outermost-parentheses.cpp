class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();;
        string ans = "";
        int count = 0;

        for(auto ch : s){
            if(ch == '('){
                if(count > 0){
                    ans.push_back(ch);
                }
                count++;
            }
            else{
                count--;
                if(count > 0){
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};