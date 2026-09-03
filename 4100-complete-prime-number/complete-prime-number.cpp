class Solution {
public:
    bool isPrime(int num){
        if(num < 2){
            return false;
        }

        for(int i=2; i*i<=num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

    bool completePrime(int num) {
        
        string nums = to_string(num);
        int n = nums.length();
        string temp = "";

        for(int i=0; i<n; i++){
            temp += nums[i];
            int t = stoi(temp);

            if(!isPrime(t) || t == 1)
                return false;
        }

        temp = "";
        for(int i=n-1; i>=0; i--){
            temp = nums[i] + temp;
            int t = stoi(temp);

            if(!isPrime(t) || t == 1)
                return false;
        }

        return true;
    }
};