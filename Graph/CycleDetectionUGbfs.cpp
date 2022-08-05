#include<bits/stdc++.h>
using namespace std;
bool iscycle(int i,vector<int> adj[],int n,vector<int>& vis,int parent){
    vis[i]=1;
    queue<pair<int,int>> q;
    q.push({i,-1});
    while(!q.empty()){
        auto c=q.front();
        q.pop();
        for(auto j:adj[c.first]){
            if(vis[j]==-1){
                vis[j]=1;
                q.push({j,c.first});
            }else if(j!=c.second)return true;
        }
    }
    return false;
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
            if(iscycle(i,adj,n,vis,-1)){
                cout<<"cycle is present"<<endl;
                return 0;
            }
        }
    }
    cout<<"cycle is not present"<<endl;
    return 0;
}