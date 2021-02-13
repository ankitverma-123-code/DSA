#include<bits/stdc++.h>
using namespace std;


unordered_map<int,list<int>> g;
vector<int> ind;

void addEdeges(int u,int v){
    g[u].push_back(v);
}


vector<int> BfsTopo(int n){
   vector<int> ans;
   ans.clear(); 
   ind.clear();
   ind.assign(n+1,0);
   for(auto ele:g){
       int vertex=ele.first;
       for(auto nbr:g[vertex]){
           ind[nbr]++;
       }
   }
   queue<int> q;
   for(int i=1;i<=n;i++){
       if(ind[i]==0){
           q.push(i);
       }
   }
   while(!q.empty()){
       ans.push_back(q.front());
       int frnt=q.front();
       q.pop();

       for(auto nbr:g[frnt]){
           ind[nbr]--;
           if(ind[nbr]==0){
               q.push(nbr);
           }
       } 
   }
   if(ans.size()!=n){
       ans={};
   }
   return ans;
}

int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        addEdeges(a,b);
    }
    for(auto all:BfsTopo(v)){
        cout<<all<<" ";
    }
    //print all nbrs of a graph

    // for(auto ele:g)
    // {
    //    int vertex=ele.first;
    //    cout<<vertex<<"-->";
    //    for(auto nbr:g[vertex]){
    //        cout<<nbr<<" ";
    //    }
    //    cout<<endl;
    // }

 return 0;
}
