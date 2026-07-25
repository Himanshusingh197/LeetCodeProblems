#include<bits/stdc++.h>
using namespace std;

int maxProduct(int n) {
    int first = 0, second = 0;

    while (n > 0) {
        int digit = n % 10;
        if (digit >= first) {
            second = first;
            first = digit;
        } 
        else if (digit > second) {
            second = digit;
        }
        n /= 10;

    }
    return first * second;
}


int main() {
    int n;
    cin >> n;
    cout << maxProduct(n) << endl;
    return 0;
}