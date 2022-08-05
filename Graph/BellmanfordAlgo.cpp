#include<bits/stdc++.h>
using namespace std;

void bellmanford(vector<tuple<int,int,int>>& adj,int n){
    vector<int> vec(n,INT_MAX);
    vec[0]=0;
    for(int i=0;i<n-1;i++){
        for(int i=0;i<adj.size();i++){
            int u=get<0>(adj[i]),v=get<1>(adj[i]),w=get<2>(adj[i]);
            if(vec[u]!=INT_MAX){
                if(vec[v]>vec[u]+w){
                    vec[v]=vec[u]+w;
                }
            }
        }
    }
    for(auto c:vec){
        cout<<c<<" ";
    }
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int u,v,w;
    vector<tuple<int,int,int>> adj;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj.push_back({u,v,w});
    }
    bellmanford(adj,n);
    return 0;
}