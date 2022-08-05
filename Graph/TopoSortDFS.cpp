#include<bits/stdc++.h>
using namespace std;

void topo(int i,vector<int> adj[],stack<int>& stk,vector<int>& vis){
    vis[i]=1;
    for(auto j:adj[i]){
        if(!vis[j])topo(j,adj,stk,vis);
    }
    stk.push(i);
    return;
}

int main(){
    int n,m;
    
    cin>>m;
    cin>>n;
    vector<int> adj[n];
    vector<int> vis(n,0);
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
       
    }
    stack<int> stk;
    for(int i=0;i<vis.size();i++){
        if(vis[i]==0){
            topo(i,adj,stk,vis);
        }
    }
    while (!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}