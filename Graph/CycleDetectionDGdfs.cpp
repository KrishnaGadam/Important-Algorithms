#include<bits/stdc++.h>
using namespace std;

//for cycle detection in directed graph we need two visited array
//we can also solve it using single array and 3 value in it 2=under processing, 1=processed, 0=not yet processed

bool cycle(int i,vector<int>& vis,vector<int>& temp,vector<int> adj[]){
    vis[i]=1;
    temp[i]=1;
    for(auto j:adj[i]){
        if(vis[j]==0){
            if(cycle(j,vis,temp,adj))return true;
        }else if(vis[j]==temp[j])return true;
    }
    temp[i]=0;
    return false;
}

int main(){
    int n,m;
    cin>>n;
    vector<int> adj[n];
    vector<int> vis(n,-1);
    vector<int> temp(n,-1);
    cin>>m;
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=0;i<vis.size();i++){
        if(vis[i]==-1){
            if(cycle(i,vis,temp,adj)){
                cout<<"cycle is present"<<endl;
                return 0;
            }
        }
    }
    cout<<"cycle is not present"<<endl;
    return 0;
}