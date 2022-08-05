#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};

vector<int> postOrder(Node* node) {
    // code here
    stack<Node*> stk;
    vector<int> post;
    Node* cur=node;
    while(cur!=NULL || !stk.empty()){
        if(cur!=NULL){
            stk.push(cur);
            cur=cur->left;
        }
        else{
            auto temp=stk.top()->right;
            if(temp==NULL){
                auto temp=stk.top();
                stk.pop();
                post.push_back(temp->data);
                while(!stk.empty() && temp==stk.top()->right){
                    temp=stk.top();
                    stk.pop();
                    post.push_back(temp->data);
                }
            }
            else cur=temp;
        }
    }
    return post;
}
int main(){
    return 0;
}