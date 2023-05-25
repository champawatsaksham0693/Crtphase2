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
void topView(Node* root){
    if (root == NULL) return ;
    vector<Node*>lvli, lvliPlus1;
    map <Node*, int> hd ;
    map <int, vector<Node*>>storingNode;
    hd[root] = 0;
    storingNode[0].push_back( root);
    
    lvli.push_back(root);
    while (lvli.size()){
        for(auto itr : lvli){
            if(itr->left!=NULL) {
                lvliPlus1.push_back(itr->left);
                hd[itr->left] = hd[itr] - 1;
                storingNode[hd[itr->left]].push_back(itr->left);
                
                
            };
            if(itr->right!=NULL) {
                lvliPlus1.push_back(itr->right);
                hd[itr->right] = hd[itr] + 1;
                storingNode[hd[itr->right]].push_back(itr->right);
            };
        }
        lvli.clear();
        swap(lvli, lvliPlus1);
    }
    for(auto itr : storingNode){
        cout<<itr.second[0]->data <<" ";
    }
}
int main(){
    Node *n2 = new Node(1);
    Node *n3 = new Node(2);
    Node *n4 = new Node(3);
    Node *n5 = new Node(4);
    Node *n1 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n4->left = n6;
    n5->right = n7;


    topView(n1);
}