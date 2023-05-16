/*
    Given an array of integers of lenght N, find out the frequency of each element 
    for example :- arr = {1,1,2,1,3,2}
    then print  1:3
                2:2
                3:1
    Time Complexity :- O(NlogN)
*/
#include<bits/stdc++.h>
using namespace std;
int main (){
    //int arr[6] = {1,1,2,1,3,2};
    int n;
    cout<<"Enter Number of elements in array : "<<endl;
    cin>>n;
    vector<int> arr(n+1,0);//nayi aaray banayi hai
    for (int i=1; i<=n; i++){//array me element insert kiye
        cout<<"Enter the Elements :  ";
        cin>>arr[i];
    }
    map<int, int> temp;
    for (int i=1; i<=n; i++){
        if (!temp.count(arr[i])){//agar temp me vo number present nahi hai to
            temp[arr[i]] =1;//to usko initially 1 diya 
        }
        else{
            temp[arr[i]] = temp[arr[i]]+1; // agar temp me vo number pehle se present hai to use 1 aage badha do
        }
    }
    for (auto itr: temp){ //Iterate the hash table and print our output 
        cout<<itr.first<<" "<<itr.second<<" "<<endl;
    }
    


}