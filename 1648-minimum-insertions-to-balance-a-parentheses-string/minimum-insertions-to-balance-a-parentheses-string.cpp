class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int count = 0;
        int open = 0;
        int close = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                open++;
            }
            else{
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                }
                else {
                    count++;
                }

                if (open > 0) {
                    open--;
                }
                else {
                    count++;
                }
            } 
        }
        return count + 2 * open;
    }
};