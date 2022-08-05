#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n;
    vector<int> adj[n];
    vector<int> vis(n,-1);
    cin>>m;
    int u,v,w;
    unordered_map<int,int> mp;
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
        ans.push_back(temp);
        for(auto j:adj[temp]){
            if(--mp[j]==0){
                q.push(j);
            }
        }
    }
    if(n==ans.size())cout<<"No cycle detected"<<endl;
    else cout<<"Cycle detected"<<endl;
    
    return 0;
}