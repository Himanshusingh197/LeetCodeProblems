#include<bits/stdc++.h>
using namespace std;

int decToBinary(int decNum){
    int ans = 0, pow = 1;
    while(decNum > 0){
        int rem = decNum%2;
        decNum /= 2;

        ans += (rem*pow);
        pow *= 10;
    }
    return ans;
}

int main(){
    int deNum = 100;

    for(int i=1; i<=100; i++){
        cout<<i<<" in binary is "<<decToBinary(i)<<endl;
    }
    return 0;
}