class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long long sum = 0, num = 0;
        while(n > 0){
            int rem = n % 10;
            if(rem != 0){
                num = num * 10 + rem;
                sum += rem;
            }
            n /= 10;
        }

        long long rev = 0;
        while(num > 0){
            int rem = num % 10;
            if(rem != 0){
                rev = rev * 10 + rem;
            }
            num /= 10;
        }

        return rev * sum;
    }
};