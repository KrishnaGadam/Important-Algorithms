//kahn's algorithm
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    
    cin>>m;
    cin>>n;
    vector<int> adj[n];
    vector<int> vis(n,-1);
    vector<int> temp(n,-1);
    unordered_map<int,int> mp;
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        mp[v]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(!mp[i])q.push(i);
    }
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(auto j:adj[temp]){
            if(--mp[j]==0){
                q.push(j);
            }
        }
    }
    
    
    return 0;
}