#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> parent(n,-1);
    vector<bool> mst(n,false);
    vector<int>  key(n,INT_MAX);
    key[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
    qu.push({0,0});
    while(!qu.empty()){
        int point=qu.top().second;
        qu.pop();
        mst[point]=true;
        for(auto c:adj[point]){
            int p=c.first;
            int q=c.second;
            if(mst[p]==false && key[p]>q){
                key[p]=q;
                qu.push({key[p],p});
                parent[p]=point;
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=key[i];
    }
    cout<<"Sum::"<<sum<<" ";
    for(int i=1;i<n;i++){
        cout<<parent[i]<<"-->"<<i<<endl;
    }

    return 0;
}