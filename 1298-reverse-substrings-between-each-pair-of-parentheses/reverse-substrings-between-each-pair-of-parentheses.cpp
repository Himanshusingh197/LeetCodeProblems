class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> lastSkipLength;
        string result;

        for(char &ch : s){
            if(ch == '('){
                lastSkipLength.push(result.length());
            }
            else if(ch == ')'){
                int l = lastSkipLength.top();
                lastSkipLength.pop();
                reverse(result.begin() + l, result.end());
            }
            else{
                result.push_back(ch);
            }
        }
        return result;
    }
};