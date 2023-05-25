#include<bits/stdc++.h>
using namespace std;
#define INFINITY __builtin_inff()
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
void printSubtreeNodes(Node* ref, int k){
    if (ref==NULL) return ;
    vector<Node *>leveli, leveliplus1;
    leveli.push_back(ref);
    int lvl =0;
    while (leveli.size()){
        for (auto itr : leveli){
            if (lvl==k) cout<<itr->data<<" ";
            if (itr->left !=NULL) leveliplus1.push_back(itr->left);
            if (itr->right !=NULL) leveliplus1.push_back(itr->right);
        }
        leveli.clear();
        swap(leveli, leveliplus1);
        lvl++;
    }

}
int distance(Node* currentNode, Node* ref ,int k){
    if (currentNode==NULL) return 1e9;
    if (currentNode == ref) {
        printSubtreeNodes(currentNode,k);
        return 0;
    }
   
    int lt = distance(currentNode->left , ref, k) +1;
    int rt = distance(currentNode->right , ref, k) +1;
    int dist = min(lt,rt);
    if (dist>=1e9) return 1e9;
    if (lt<1e9) printSubtreeNodes(currentNode->right, k-dist-1);
    if (rt<1e9) printSubtreeNodes(currentNode->left, k-dist-1);
    if (dist == k) cout<<currentNode->data<<" ";
    return dist;

}


int main(){
    Node *n1 = new Node (1);
    Node *n2 = new Node (2);
    Node *n3 = new Node (3);
    Node *n4 = new Node (4);
    Node *n5 = new Node (5);
    Node *n6 = new Node (6);
    Node *n7 = new Node (7);
    Node *n8 = new Node (8);
    Node *n9 = new Node (9);
    Node *n10 = new Node (10);
   
    

    n1->left = n2;
    n1->right = n4;
    n2->left = n3;
    n2->right= n5;
    n3->left = n6;
    n3->right = n7;
    n6->left = n10;
    n7->left = n8;
    n7->right = n9;
    cout<<"BFS of tree is:"<<endl;
    bfs(n1);
    
    distance(n1, n3, 2);
    
    
}
