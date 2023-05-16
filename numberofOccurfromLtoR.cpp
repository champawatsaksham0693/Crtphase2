/*
    We have given an array 
    arr = {1,5,1,1,2,3,1}
    We have give queries = {x,y,z}
    we have to find the occurence of z from x to y 
    for example we have given query 1 :- x = 1 and y = 6 and z = 1 then output is 3
    Time Complexity :- O()

    array = {1,1,2,3,3,2,1,1}
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

    map <int, vector<int>> temp; //
    //temp[0]=1;
    for (int i=0; i<n; i++){
        temp[arr[i]].push_back(i);
    }

    int q; 
    cout<<"Enter the number of queries"<<endl;
    cin >>q;
    while (q--){
        int x, y, z;
        cout<<"Enter the value of x and y and z"<<endl;
        cin >> x >> y >> z;

        int low = 0, high = (int)temp[z].size()-1;
        int firstOccurence = -1;
        while(low<= high){
            int mid = (low + high)/2;
            if (temp[z][mid]>=y){
                firstOccurence = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
            
        }
        low = 0, high = (int)temp[z].size()-1;
        int lastOccurence = -1;
        while(low<= high){
            int mid = (low + high)/2;
            if (temp[z][mid]<=y){
                lastOccurence = mid;
                low = mid+1;
            }
            else {
                
                high = mid-1;
            }
            
        }
        cout << firstOccurence <<" "<< lastOccurence << endl;

        if (firstOccurence == -1 || lastOccurence == -1){
            cout << 0 << endl;
        }
        else{
            int ans = lastOccurence - firstOccurence + 1;
            cout<< ans << endl;
        }
    }
    
}