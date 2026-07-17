#include<bits/stdc++.h>
using namespace std;

int main(){
    int m = 3, n = 3;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int i = m-1, j = n-1, k = m+n-1;

    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j]){
            nums1[k--] = nums1[i--];
        }
        else{
            nums1[k--] = nums2[j--];
        }
    }

    while(j >= 0){
        nums1[k--] = nums2[j--];
    }

    cout << "The merged sorted array is: ";
    for(int num : nums1){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}