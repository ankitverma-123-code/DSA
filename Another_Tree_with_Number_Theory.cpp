#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>> g;

void addEdeges(int u,int v){
    g[u].push_back(v);
}

int solve(int v,int w)
{
    if(w==0) return w;
    if(g.find(v)==g.end()){
        return 0;
    }
    if((g.find(v)!=g.end()) && (g[v].size()==1)){
        for(auto ele:g[v]){
            return solve(ele,w);
        }
    }
        int k=g[v].size();
        if(w%k!=0) return w;
        for(auto ele:g[v]){
            return solve(ele,w/k);
        }
    return w;
}

int main() {
    
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        addEdeges(a,i);
    }
    int t;
    cin>>t;
    while(t--){
        int v,w;
        cin>>v>>w;
        cout<<solve(v,w)<<endl;
    }
}
