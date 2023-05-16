//to find the sum of subarray 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >>n; //input liya hai 
    vector<int> arr(n+1,0);//nayi aaray banayi hai
    for (int i=1; i<=n; i++){//array me element insert kiye
        cin>>arr[i];
    }
    vector<int> pref(n,0);//prefix banaya 
    pref[1] = arr[1]; //initially prefix of 1 jo hoga vo array of 1 tak ka sum hoga 
    for (int i=2; i<=n; i++){//loop i=2 se chalaya 
        pref[i] = pref[i-1]+arr[i]; //prefix of i nikalne ka formula
    }
    int q; 
    cin >>q; //number of queries insert karvayi 
    for(int i=0; i<q; i++){
        int l, r; 
        cin>>l>>r; // l matlb left , r matlab right input liye kaha se kaha tak ka sum chahiye 
        cout<<"Sum is :"<<pref[r]-pref[l-1]<<endl; // sum print kara hai l se r tak 
    }
}