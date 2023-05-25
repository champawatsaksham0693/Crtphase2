/*  
    Level oreder traversal of tree using an array
    time compexity of swap of two array is O(1)

*/

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
int fact (int n){
    if (n==0 || n==1) return 1;
    else return n*fact(n-1);
}
void bfs(Node *root){
    if (root == NULL) return ;
    vector<Node *>leveli, leveliplus1;
    leveli.push_back(root);
    while (leveli.size()){
        for (auto itr : leveli){
            cout<<itr->data<<" ";
            if (itr->left !=NULL) leveliplus1.push_back(itr->left);
            if (itr->right !=NULL) leveliplus1.push_back(itr->right);
        }
        leveli.clear();
        swap(leveli, leveliplus1);
    }
    cout<<endl;
}
void leftView (Node *root){
    if (root == NULL) return ;
    vector<Node *>leveli, leveliplus1;
    leveli.push_back(root);
    while (leveli.size()){
        cout<<leveli[0]->data<<" ";
        for (auto itr : leveli){
            // cout<<itr->data<<" ";
            if (itr->left !=NULL) leveliplus1.push_back(itr->left);
            if (itr->right !=NULL) leveliplus1.push_back(itr->right);
        }
        leveli.clear();
        swap(leveli, leveliplus1);
    }
    cout<<endl;
}
void rightView(Node* root){
    if(root==NULL) return;
    vector<Node*> lvli, lvliPlus1;
    lvli.push_back(root);
    while(lvli.size()){
        cout<<lvli.back()->data<<" ";
        for(auto itr : lvli){
            if(itr->left!=NULL) lvliPlus1.push_back(itr->left);
            if(itr->right!=NULL) lvliPlus1.push_back(itr->right);
        }
        lvli.clear();
        swap(lvli, lvliPlus1);
    }
    cout<<endl;
}


int possibleLevelOrderTraversal(Node* root){
    if(root==NULL) return 1;
    int ans = 1;
    vector<Node*> lvli, lvliPlus1;
    lvli.push_back(root);
    while(lvli.size()){
        ans= ans *(fact(lvli.size()));
        for(auto itr : lvli){
            if(itr->left!=NULL) lvliPlus1.push_back(itr->left);
            if(itr->right!=NULL) lvliPlus1.push_back(itr->right);
        }
        lvli.clear();
        swap(lvli, lvliPlus1);
    }
    return ans;
}


int main(){
    Node *n1 = new Node (1);
    Node *n3 = new Node (2);
    Node *n4 = new Node (8);
    Node *n6 = new Node (4);
    Node *n7 = new Node (6);
    Node *n2 = new Node (5);
    Node *n5 = new Node (3);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n4->right = n7;
    cout<<"BFS of tree is:"<<endl;
    bfs(n1);
    cout<<"Left View of tree is:"<<endl;
    leftView(n1);
    cout<<"Right view of tree is"<<endl;
    rightView(n1);
    cout<< "possible bfs is:" <<possibleLevelOrderTraversal(n1);
}
