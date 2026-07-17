#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 123;
    int rev = 0;

    while(x > 0){
        int rem = x % 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && rem > 7)) {
            cout << "Overflow occurred. Cannot reverse the integer." << endl;
            return 0;
        }
        rev = rev * 10 + rem;
        x /= 10;
    }
    cout << "The reverse of the integer is: " << rev << endl;

    return 0;
}