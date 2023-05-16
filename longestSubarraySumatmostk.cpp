/*
    Given an array  arr = {1,2,3,1,2} and k = 6 then the output is 3
    for example:- arr = {1,2,1,2,1,3,5,9} and k = 8 then the output is 5
    We need to find the maximum length of subarray whose sum is less than and equal to k
    Time Complexity = O(NlogN)
    Space Complexity = O(N)
    // Very Very Important point  apply binary search on monotonus search space (yyyynnnnnn...) or monotonus(nnnnyyyyy...) 
    // We can't apply binary search on non-monotonus search space 
    method 1 :- binary search + prefix sum (use only this)
    method 2 :- two pointers 
    Output is 3
*/
//code here

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cout<<"Enter the number of elements in array:"<<endl;
    cin>>n;
    cout<<"Enter the Element of array : "<<endl;
    vector<int> arr(n,0);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int>pref(n,arr[0]); //initially prefix of 1 jo hoga vo array of 1 tak ka sum hoga 
    for (int i=1; i<n; i++){//loop i=2 se chalaya 
        pref[i] = pref[i-1] + arr[i];
    }

    int k; 
    cout<<"Give the Sum is :"<<endl;
    cin>>k;

    int low = 0 , high = n, ans = -1;
    while (low <= high){
        int mid = low+(high-low)/2;
        bool flag = false;

        for (int i=0; i<n; i++){
            int endPoint = i;
            int startPoint = i-mid+1;
            if (startPoint<0) continue;
            if (pref[endPoint] - (startPoint-1 > 0 ? pref[startPoint-1] : 0) <= k){
                flag = true;
                break;
            }
        }

        if (flag == true){
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    cout<<"Maximum Length of Subarray is :" << ans << endl ;
    return 0;
}
