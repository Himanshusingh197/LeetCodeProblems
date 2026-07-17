#include<bits/stdc++.h>
using namespace std;

int DigitSum(int n){
    int sum= 0,digit;
        while(n > 0){
            digit = n%10;
            sum = sum + (digit*digit);
            n = n/10;
        }
    return sum;
    }
bool isHappy(int n) {
    int slow = n;
    int fast = DigitSum(n);

    while(fast != 1 && slow != fast){
        slow = DigitSum(slow);
        fast = DigitSum(DigitSum(fast));
    }
    return fast == 1;
}

int main(){
    int n = 19;
    if(isHappy(n)){
        cout << n << " is a happy number." << endl;
    } else {
        cout << n << " is not a happy number." << endl;
    }
    return 0;
}