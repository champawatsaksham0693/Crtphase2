/*We have given a matrix of n rows and m column 
We have to find the 2d prefix sum at certain positon (i,j) or we have to find the sum from (x1,y1) to (x2,y2)  */
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int n, m;//declare row and column
    ll i, j;
    cin>>n>>m;// input number of rows and columns 
    vector<vector<ll>>matrix(n+1, vector<ll>(m+1,0)); //declare matrix
    vector<vector<ll>>dp(n+1, vector<ll>(m+1,0)); // declare dp

    for (i =1; i<=n; i++){//loop for row
        for(j=1; j<=n; j++){//loop for column
            cin>>matrix[i][j];//matrix ka input
        }
    }
    cout<<"We have to find the sum at (i,j) position "<<endl;
    for (i =1; i<=n; i++){ // row ka loop
        for(j=1; j<=n; j++){ // column ka loop
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j]; // sum at (i,j) position nikalne ka formula 
            cout<<dp[i][j]<<" "; //print the sum
        }
        cout<<endl;
        
    }
    int q; 
    cin>>q; // input the number of queries
    cout<<"If we have given x1, y1, x2, y2"<<endl;
    for (int i=0; i<q; i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2; //input x1,y1 and x2,y2
        cout<<dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]<<endl; // (x1,y1) se lekar (x2,y2) tak ke number ka sum nikalne ka formula 
    }



}