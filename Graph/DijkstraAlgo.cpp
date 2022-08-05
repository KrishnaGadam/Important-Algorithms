#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<pair<int,int>> adj[],int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<int> vec(n,INT_MAX);
    vec[0]=0;
    q.push({0,0});
    while(!q.empty()){
        auto temp=q.top();
        q.pop();
        for(auto c:adj[temp.second]){
            if(vec[c.first]>vec[temp.second]+c.second){
                vec[c.first]=vec[temp.second]+c.second;
                q.push({vec[c.first],c.first});
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
    vector<pair<int,int>> adj[n];
    cin>>m;
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(adj,n);

    return 0;
}