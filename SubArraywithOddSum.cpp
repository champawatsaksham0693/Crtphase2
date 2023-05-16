/*We have given an array of integers , Find out the numbers of subarray having odd sum 
    for example arr = {1,2,3,-1,2}
    Time Complexity = O(NlogN)
    Leetcode 1524 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cout<<"Enter the numbers of Element present in the array : "<<endl;
    cin >>n; //input liya hai 
    cout<<"Enter the Element of array : "<<endl;
    vector<int> arr(n+1,0);//nayi aaray banayi hai
    for (int i=1; i<=n; i++){//array me element insert kiye
        cin>>arr[i];
    }
    int k; 
    // cout<<"Given Sum is :"<<endl;
    // cin>>k; //k is sum of subarrays
    vector<int>pref(n+1,0);
    pref[1] = arr[1]; //initially prefix of 1 jo hoga vo array of 1 tak ka sum hoga 
    for (int i=2; i<=n; i++){//loop i=2 se chalaya 
        pref[i] = pref[i-1] + arr[i];
    }
    int ans =0;
    map<int,int>temp;
    temp[0] = 1;
    for (int i=1; i<=n; i++) {
        if (temp.count((pref[i]-k)%2!=0)){ //odd
            ans ++;
        }
        temp[pref[i]-k]++;    
    }
    cout<<ans<<endl;
}