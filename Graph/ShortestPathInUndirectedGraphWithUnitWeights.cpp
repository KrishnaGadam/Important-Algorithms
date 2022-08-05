#include<bits/stdc++.h>
using namespace std;


void shortestPath(vector<int> adj[],int n){
    vector<int> vec(n,INT_MAX);
    vec[0]=0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(auto c:adj[temp]){
            if(vec[c]>vec[temp]+1){
                vec[c]=vec[temp]+1;
                q.push(c);
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
    vector<int> adj[n];
    cin>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    shortestPath(adj,n);

    return 0;
}