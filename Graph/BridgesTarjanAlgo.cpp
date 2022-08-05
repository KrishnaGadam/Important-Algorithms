#include<bits/stdc++.h>
using namespace std;


int Time=0;
vector<pair<int,int>> ans;
void helper(int node,vector<int> adj[],vector<int>& vis,vector<int> &ins,vector<int> &low,int parent){
    low[node]=ins[node]=Time++;
    vis[node]=1;
    for(auto k:adj[node]){
        if(k==parent)continue;
        if(!vis[k]){
            helper(k,adj,vis,ins,low,node);
            low[node]=min(low[node],low[k]);
            if(low[k]>ins[node]){
                ans.push_back({node,k});
            };
        }
        else{
            low[node]=min(low[node],ins[k]);
        }
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
        adj[v].push_back(u);
    }
    vector<int> vis(n,0);
    vector<int> ins(n,-1);
    vector<int> low(n,-1);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            helper(i,adj,vis,ins,low,-1);
        }
    }
    for(auto c:ans){
        cout<<c.first<<"-->"<<c.second<<endl;
    }
    
}