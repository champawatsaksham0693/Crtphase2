/*Given an array 
    arr = {1,2,-4,3,1}
    prefixSumArray = {1,3,-1,2,3} 
    1. humko isko ese rearrange karna hai ki jo apna negative element jo hoga vo maximum position pe aayega 
    2. agar esa rearrangement nahi ho paata hai jaha sum negative nahi hua hai to return -1 karna hai or agar
         negative ho jaata hai to vo index return karna hai jaha par vo negative karta hai
    Solution :- isme sabse pehle hum positive numbers bharenge or jab negative number aayenge to chote 
                negative numbers pehle bharenge jis se prefix sum jo hoga vo dheere dheere kam hoga
                then uske baad bade numbers bhare jaayenge 

    Time Complexity :- O(NlogN)
*/
//comparators
#include<bits/stdc++.h>
using namespace std;
bool comp(int a,int b){
    return a>b;
}
int main(){
    int n;
    cout<<"Enter Number of Elements : "<<endl;
    cin>> n;
    cout<<"Enter the Element of array : "<<endl;
    vector<int> arr(n+1,0);//nayi aaray banayi hai
    for (int i=1; i<=n; i++){//array me element insert kiye
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end(), comp);
    int sum = 0;
    for(int i=0; i<=n; i++){
        sum += arr[i];
        if (sum<0){
            cout<<"Sum is negative at index:"<<i<<endl;
            return 0;
        }
    }
    cout<< -1 <<endl;

    
}