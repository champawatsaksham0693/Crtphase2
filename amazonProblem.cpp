/*
    We have given N players with different features like swimming , chess, leadership, communication skills etc.
                        scores of player 1        scores of player 2         scores of player 2
    swimming                    5                       9                           1
    chess                       4                       9                           1
    leadership                  6                       9                           1
    communication               3                       9                           1
    comparator is used for custom sort
*/

#include<bits/stdc++.h>
using namespace std;
bool comp( vector<int>player1, vector<int>player2 ){
    int k = player1.size();
    int count = 0;
    for (int i=0; i<k; i++){
        if (player1[i] > player2[i] ) count++;
        return count >=k-1;     
    }
}
int main(){
    vector<vector<int>> score = {{5, 2, 1, 2}, {2, 3, 1, 2}, {1, 9, 7, 7}, {2, 3, 1, 1}};
    sort(score.begin(), score.end(), comp);
    for(auto itr: score) {
        for(auto element: itr) cout<<element<<" ";
        cout<<endl;
    }
}
