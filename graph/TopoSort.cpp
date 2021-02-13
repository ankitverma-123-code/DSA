#include<bits/stdc++.h>
using namespace std;


int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void addEdeges(int u,int v){
   adj[u].push_back(v);
}

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}
int main(){
    cin>>n;
    int e;
    cin>>e;
    for(int i=0;i<n;i++){
       int u;
       int v;
       cin>>u>>v;
       addEdeges(u,v);
    }
    topological_sort();
    for(auto i:ans){
        cout<<i<<" ";
    }
}