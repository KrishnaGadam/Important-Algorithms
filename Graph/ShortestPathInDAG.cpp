#include<bits/stdc++.h>
using namespace std;

void topo(int i,vector<pair<int,int>> adj[],stack<int>& stk,vector<int>& vis){
    vis[i]=1;
    for(auto j:adj[i]){
        if(!vis[j.first])topo(j.first,adj,stk,vis);
    }
    stk.push(i);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    vector<int> vis(n,0);
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
       
    }
    stack<int> stk;
    for(int i=0;i<vis.size();i++){
        if(vis[i]==0){
            topo(i,adj,stk,vis);
        }
    }
    
    vector<int> vec(n,INT_MAX);
    vec[0]=0;
    while(!stk.empty()){
        int t=stk.top();
        stk.pop();
        if(vec[t]!=INT_MAX){
            for(auto j:adj[t]){
                if(vec[t]+j.second<vec[j.first]){
                    vec[j.first]=vec[t]+j.second;
                }
            }
        }
        
    }
    for(auto c:vec)cout<<c<<" ";

    return 0;
}