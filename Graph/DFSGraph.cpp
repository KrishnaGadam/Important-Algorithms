#include<bits/stdc++.h>
using namespace std;

void DFS(int i,vector<int> adj[],int n,vector<int>& vis){
    cout<<i<<" ";
    vis[i]=1;
    for(auto c:adj[i]){
        if(vis[c]==-1){
            DFS(c,adj,n,vis);
        }
    }
    
}

int main(){
    int n,m;
    cin>>n;
    vector<int> adj[n];
    vector<int> vis(n,-1);
    cin>>m;
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<vis.size();i++){
        if(vis[i]==-1){
            DFS(i,adj,n,vis);
        }
    }
    

    return 0;
}