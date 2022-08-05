#include<bits/stdc++.h>
using namespace std;
bool iscycle(int i,vector<int> adj[],int n,vector<int>& vis,int parent){
    vis[i]=1;
    for(auto c:adj[i]){
        if(vis[c]!=-1 && c!=parent){
            return true;
        }else if(vis[c]==-1){
            if(iscycle(c,adj,n,vis,i))return true;
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