#include<bits/stdc++.h>
using namespace std;



int Time=1;
void helper(int node,vector<int> adj[],vector<int> &vis,vector<int> &ins,vector<int> &low,vector<int> &ans,int parent){
    low[node]=ins[node]=Time++;
    vis[node]=1;
    int child=0;
    for(auto c:adj[node]){
        
        if(c==parent)continue;
        if(!vis[c]){
            helper(c,adj,vis,ins,low,ans,node);
            low[node]=min(low[c],low[node]);
            if(low[c]>=ins[node] && parent!=-1)ans[node]=1;
            child++;
        }
        else{
            low[node]=min(low[node],ins[c]);
        }
    }
    if(child>1 && parent==-1)ans[node]=1;
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
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            helper(i,adj,vis,ins,low,ans,-1);
        }
    }
    
    vector<int> vec;
    for(int i=0;i<ans.size();i++){
        if(ans[i])vec.push_back(i);
    }
    if(vec.size()==0)vec.push_back(-1);
    for(auto c:vec)cout<<c<<" ";
    
    return 0;
}