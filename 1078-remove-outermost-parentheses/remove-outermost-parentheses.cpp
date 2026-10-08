class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        stack<char> st;
        string ans = "";

        for(auto ch : s){
            if(ch == '('){
                if(!st.empty()){
                    ans.push_back(ch);
                }
                st.push(ch);
            }
            else{
                if(ch == ')'){
                    st.pop();
                    if(!st.empty()){
                        ans.push_back(ch);
                    }
                }
            }
        }
        return ans;
    }
};