#include<bits/stdc++.h>
using namespace std;

int parent[1000000];
int Rank[100000];

int find(int c){
    if(c==parent[c])return c;
    return parent[c]=find(parent[c]);
}
void Union(int u,int v){
    int p=find(u);
    int q=find(v);
    if(Rank[p]<Rank[q]){
        parent[p]=q;
    }
    else if(Rank[p]>Rank[q]){
        parent[q]=p;
    }
    else{
        parent[q]=p;
        Rank[p]++;
    }
    
}
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
    vector<tuple<int,int,int>> vec;
    //vector<tuple<int,int,int>> arr;
    int ans=0;
    for(int i=0;i<n;i++){
        for(auto c:adj[i]){
            vec.push_back(make_tuple(c.second,i,c.first));
        }
    }
    for(int i=0;i<n;i++){
        parent[i]=i;
        Rank[i]=0;
    }
    sort(vec.begin(),vec.end(),[](auto a,auto b){
        return (get<0>(a))<(get<0>(b));
    });
    for(int i=0;i<vec.size();i++){
        int w=get<0>(vec[i]);
        int u=get<1>(vec[i]);
        int v=get<2>(vec[i]);
        if(find(u)!=find(v)){
            //arr.push_back(vec[i]);
            ans+=w;
            Union(u,v);
        }
    }
    cout<<"MINIMUM cost::"<<ans<<endl;
}