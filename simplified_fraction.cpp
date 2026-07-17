#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(gcd(i,j)==1) cout<<i<<"/"<<j<<" ";
        }
    }
    return 0;
}