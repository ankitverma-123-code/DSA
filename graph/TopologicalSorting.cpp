#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
unordered_map<int,list<int>> g;
unordered_map<int,int> color;
vi vis;
void addEdeges(int u,int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

bool dfs(int node, int parent)
{
    color[node]=1;
    for(auto child: g[node])
    {
        if ( child!=parent && color[child] == 1 )
        {
        // You can remove the condition for child!=parent, when you want to detect even the  2 node cycles in directed graph like 1->2, 2->1
            return true;
        }
    else if( color[child] == 0 )
        {  
            bool temp = dfs(child, node);
            if( temp == true) return true;
        }
    }
    color[node]=2;
    return false;
}
vi TopoForDfs(){
    
}


int main() {
    
    int e,n;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        addEdeges(a,b);
    }

    vi ans=TopoForDfs();
}
