#include<bits/stdc++.h>
using namespace std;

bool isbypartite(int i,vector<int> adj[],int n,vector<int>& vis){
    for(auto c:adj[i]){
        if(vis[c]==-1){
            vis[c]=vis[i]^1;
            if(!isbypartite(c,adj,n,vis))return false;
        }else if(vis[c]==vis[i]){
            return false;
        }
    }
    return true;
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
            vis[i]=0;
            if(!isbypartite(i,adj,n,vis)){
                cout<<"Bypartite not present"<<endl;
                return 0;
            }
        }
    }
    cout<<"Bypartite is present"<<endl;
    return 0;
}