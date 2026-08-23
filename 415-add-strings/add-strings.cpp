class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.length() - 1;
        int n = num2.length() - 1;

        int carry = 0;
        string result = "";

        while(m >= 0 || n >= 0 || carry){
            int digit1 = 0;
            int digit2 = 0;

            if(m >= 0){
                digit1 = num1[m] - '0';
            }

            if(n >= 0){
                digit2 = num2[n] - '0';
            }

            int sum = digit1 + digit2 + carry;
            result += (sum % 10) + '0';
            carry = sum / 10;
            m--;
            n--;
        }
        reverse(result.begin(), result.end());

        return result;
    }
};