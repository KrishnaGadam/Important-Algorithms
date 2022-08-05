#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};

vector <int> preorder(Node* root)
{
    stack<Node*> stk;
    stk.push(root);
    vector<int> preorder;
    while(!stk.empty()){
        auto cur=stk.top();
        stk.pop();
        preorder.push_back(cur->data);
        if(cur->right){
            stk.push(cur->right);
        }
        if(cur->left){
            stk.push(cur->left);
        }
    }
    return preorder;
}

int main(){
    return 0;
}