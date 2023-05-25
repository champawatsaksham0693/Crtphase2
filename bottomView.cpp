#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void bottomView(Node* root){
    if (root == NULL) return ;
    vector<Node*>lvli, lvliPlus1;
    map <Node*, int> hd ;
    map <int, vector<pair<Node*,int>>>storingNode;
    hd[root] = 0;
    storingNode[0].push_back( {root,0});
    int lvl = 0;
    lvli.push_back(root);
    while (lvli.size()){
        for(auto itr : lvli){
            if(itr->left!=NULL) {
                lvliPlus1.push_back(itr->left);
                hd[itr->left] = hd[itr] - 1;
                if (storingNode[hd[itr->left]].size() && (storingNode[hd[itr->left]].back().second != lvl+1)){
                    storingNode[hd[itr->left]].clear();
                }   
                storingNode[hd[itr->left]].push_back({itr->left, lvl+1});       
                
            };
            if(itr->right!=NULL) {
                lvliPlus1.push_back(itr->right);
                hd[itr->right] = hd[itr] + 1;
                if (storingNode[hd[itr->right]].size() && (storingNode[hd[itr->right]].back().second != lvl+1)){
                    storingNode[hd[itr->right]].clear();
                }   
                storingNode[hd[itr->left]].push_back({itr->right, lvl+1});  
            };
        }
        lvli.clear();
        swap(lvli, lvliPlus1);
        lvl++;
    }
    for(auto itr : storingNode){
        for(auto elem : itr.second){
            cout<<elem.first->data <<" ";
        }
       
    }
}
int main(){
    Node *n1 = new Node(5);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(1);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    n1->left = n5;
    n1->right = n2;
    n2->left = n6;
    n2->right = n7;
    n5->left = n3;
    n5->right = n4;


    bottomView(n1);
}