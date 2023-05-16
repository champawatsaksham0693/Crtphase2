#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> marksMap;//initialize the marksMap
    marksMap[3089] = 123;//syntax for insertion and updation 
    marksMap[3012] = 124;
    marksMap[3076] = 125;
    marksMap[3099] = 128;
    marksMap[3080] = 123;
    
    for (auto itr: marksMap){ //iterate the elements and print the hash table
        int key = itr.first; 
        int val = itr.second;
        cout<<key<<" "<<val<<" "<<endl;
        //It print the table in the ascending order
    }
    cout<<marksMap.count(3076)<<endl; //return the answer in 1 or 0
    marksMap.erase(3012); //syntax for deletion from hash map 
    for (auto itr: marksMap){ //Reiterate the dunction after deletion 
        int key = itr.first;
        int val = itr.second;
        cout<<key<<" "<<val<<" "<<endl;
    }
}