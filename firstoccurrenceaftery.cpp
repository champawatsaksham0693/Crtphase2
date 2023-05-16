/*
    Let We have given an array of Integer 
    arr = {1,2,3,1,1,1,2,3,2}
    x ki first occurrence after index y nikalna hai 
    binary search unsorted array pe bhi lag sakta hai 
    Time Complexity = O(NlogN + qlogN)
    first create a hash map :-
    1 = {0,3,4,5}
    2 = {1,6,8}
    3 = {2,7}
    for example query 1 if x = 2 and y = 7 then output is 8
                query 2 if x = 1 and y = 2 then output is 3  
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cout<<"Enter the numbers of Element present in the array : "<<endl;
    cin >>n; //input liya hai 
    cout<<"Enter the Element of array : "<<endl;
    vector<int> arr(n);//nayi aaray banayi hai
    for (int i=0; i<n; i++){//array me element insert kiye
        cin>>arr[i];
    }

    map <int, vector<int>> temp;
    //temp[0]=1;
    for (int i=0; i<n; i++){
        temp[arr[i]].push_back(i);
    }


    int q; 
    cout<<"Enter the number of queries"<<endl;
    cin >>q; //number of queries insert karvayi 
    while (q--){
        int x, y; 
        cout<<"Enter x and y"<<endl;
        cin >> x >> y;

        int low = 0, high = (int)temp[x].size()-1;
        int ans = -1;
        while(low<= high){
            int mid = (low + high)/2;
            if (temp[x][mid]>=y){
                ans = temp[x][mid];
                high = mid-1;
            }
            else {
                low = mid+1;
            }
            
        }
        cout<< ans << endl;
        
    }

    return 0;
}