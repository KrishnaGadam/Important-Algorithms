#include<bits/stdc++.h>
using namespace std;

bool isbypartite(int i,vector<int> adj[],int n,vector<int>& vis,int parent){
        vis[i]=1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            auto c=q.front();
            q.pop();
            for(auto j:adj[c]){
                if(vis[j]==-1){
                    vis[j]=vis[c]^1;
                    q.push(j);
                }else if(vis[j]==vis[c])return false;
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
            if(isbypartite(i,adj,n,vis,-1)){
                cout<<"Graph is bypartite"<<endl;
                return 0;
            }
        }
    }
    cout<<"Graph is not bypartite graph"<<endl;
    return 0;
}