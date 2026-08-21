class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();

        vector<int> ans(m + n, 0);
        int product = 1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                product = (num1[i] - '0') * (num2[j] - '0');

                int pos1 = i + j;
                int pos2 = i + j + 1;

                int sum = product + ans[pos2];

                ans[pos2] = sum % 10;
                ans[pos1] += sum / 10; 
            }
        }

        string res = "";
        for(auto digit : ans){
            if(!(res.empty() && digit == 0)){
                res += char(digit + '0');
            }
        }

        return res.empty() ? "0" : res;
    }
};