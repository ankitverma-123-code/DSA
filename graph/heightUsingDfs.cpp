#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>> g;
unordered_map<int,int> visited;

void addEdeges(int u,int v){
    g[u].push_back(v);
    g[v].push_back(u);
}
unordered_map<int,int> level;

int height=0;
int dfs(int src){
    
    visited[src]=true;

    for(auto nbr: g[src]){
        if(!visited[nbr]){
            level[nbr]=level[src]+1;
            dfs(nbr);
        }
    }
    int ans=0;
    for(auto elements:level){
       ans=max(ans,elements.second);  
    }
   return ans;
}

int main() {
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        addEdeges(a,b);
    }
    int src=1;
    level[src]=0;
    cout<<dfs(src);
    
}
