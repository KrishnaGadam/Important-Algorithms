#include<bits/stdc++.h>
using namespace std;

void BFS(int i,vector<int> adj[],int n,vector<int>& vis){
    queue<int> q;
    q.push(i);
    vis[i]=1;
    while (!q.empty())
    {
       int j=q.front();
       q.pop();
       
       cout<<j<<" ";
       for(auto c:adj[j])if(vis[c]==-1){
           q.push(c);
           vis[c]=1;
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
            BFS(i,adj,n,vis);
        }
    }
    

    return 0;
}