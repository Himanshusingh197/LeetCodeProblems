#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;   
            return digits;
        }
        digits[i] = 0;     // carry forward
    }

        // If all digits were 9 (e.g., 999 → 1000)
    digits.insert(digits.begin(), 1);
    return digits;
}

int main(){
    vector<int> digits = {9, 2, 9};
    vector<int> result = plusOne(digits);

    cout << "Result after adding one: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;

    return 0;
}