//Sort an Array in descending order using comparator
#include<bits/stdc++.h>
using namespace std;
bool comp(int a, int b){
    return a>b;
}
int main(){
    int arr[5] ={2,5,8,4,1};
   sort(begin(arr), end(arr), comp());
    return 0;
}