#include<bits/stdc++.h>
using namespace std;

int main (){
    int n ;
    cout<<"Enter the number of elements in array:"<<endl;
    cin>>n;
    cout<<"Enter the Element of array : "<<endl;
    vector<int> arr(n,0);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int k;
    cout<<"Give the value of Sum:"<<endl;
    cin>>k;

    int ptr1 = 0, ptr2 = 0, sum = 0, ans = 0;
    while (ptr2<n){
        sum += arr[ptr2];
        while (sum>k){
            sum -= arr[ptr1];
            ptr1++;
        }
        ans = max(ans,ptr2-ptr1+1);
        ptr2++;
    }
    cout<<"Maximum Length of Subarray whose Sum is less than k is:"<<ans<<endl;
}