#include<bits/stdc++.h>
using namespace std;

void topo(int node,vector<int> adj[],stack<int>& stk,vector<int>& vis){
    vis[node]=1;
    for(auto c:adj[node]){
        if(!vis[c]){
            topo(c,adj,stk,vis);
        }
    }
    stk.push(node);
}
void dfs(int node,vector<int> transpose[],vector<int>& vis){
    vis[node]=1;
    for(auto c:transpose[node]){
        if(!vis[c])dfs(c,transpose,vis);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    stack<int> stk;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i])topo(i,adj,stk,vis);
    }
    vector<int> transpose[n];
    for(int i=0;i<n;i++){
        vis[i]=0;
        for(auto c:adj[i]){
            transpose[c].push_back(i);
        }
    }
    int count=0;
    while(!stk.empty()){
        int k=stk.top();
        stk.pop();
        if(!vis[k]){
            count++;
            dfs(k,transpose,vis);
        }
    }
    cout<<"Strongly connected components::"<<count<<endl;
    return 0;
}