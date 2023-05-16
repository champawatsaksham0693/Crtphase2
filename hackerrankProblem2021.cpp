/*
    Find the maximum area of sub matrix whose sum is less than or equal to k;
    Constraint :- N = 10^3
    0 <= arr[i][j] <= 10^9

    Time Complexity O(N*N logN)
    Agar isme humko square matrix nahi di hogi 
    Leet Code =  1292
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of rows and column:"<<endl;
    cin >> n >> m ;
    vector<vector<int>>matrix(n+1, vector<int>(m+1,0)); //declare matrix
    cout<<"Enter the element of Matrix :"<<endl;
    for (int i = 1; i<=n; i++){//loop for row
        for(int j=1; j<=m; j++){//loop for column
            cin>>matrix[i][j];//matrix ka input
        }
    }

    int k; 
    cout<<"Give the Sum is :"<<endl;
    cin>>k;
    vector<vector<int>>pref(n+1, vector<int>(m+1,0)); // declare prefix
    for (int i =1; i<=n; i++){ // row ka loop
        for(int j=1; j<=m; j++){ // column ka loop
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + matrix[i][j]; // sum at (i,j) position nikalne ka formula 
            //cout<<pref[i][j]<<" "; //print the sum
        }
    }
    int low = 0 , high = n , ans = -1;
    while (low <= high ) {
        int mid = low+(high-low)/2;
        bool flag = false;
        for (int i=1; i<=n; i++){
            for (int j = 1 ; j <= m; j++){
                int x2 = i, y2 = j;
                int x1 = i-mid+1 , y1 = j-mid+1;
                if (x1<=0 || y1<=0) continue;
                int sum = pref[x2][y2] - pref[x2][y1-1] - pref[x1-1][y2] + pref[x1-1][y1-1];
                if (sum <= k){
                    flag = true; // flag ko true update kiya hai 
                }
            }
        }
        if (flag){
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }

    }
    cout<<"Maximum Area of Sub matrix is :" << ans*ans << endl ;
    return 0;
}