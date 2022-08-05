#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};
vector<int> inOrder(Node* root) {
    stack<Node*> stk;
    Node* cur=root;
    vector<int> inorder; 
    while(true){
        if(cur!=NULL){
            stk.push(cur);
            cur=cur->left;
        }
        else{
            if(stk.empty())return inorder;
            auto c=stk.top();
            stk.pop();
            inorder.push_back(c->data);
            cur=c->right;
        }
    }
    return inorder;
}
int main(){
    return 0;
}