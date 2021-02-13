#include <bits/stdc++.h> 
using namespace std;


int main(){
    
  vector<pair<char,int>> map;
  int k;
  cin>>k;
  string s;
  cin>>s;
  map.push_back({s[0],1});
  for(int i=1;i<s.size();i++){
      if(s[i]==s[i-1]){
          map.back().second++;
      }
      else{
          map.push_back({s[i],1});
      }
  }
  int add=0;
  int fre=1;
  for(auto it:map){
      freq=max(freq,it.second);
      
  }
  cout <<map.size()<<endl;
   return 0;
}