#include <bits/stdc++.h> 

using namespace std;

vector<string> keypad{ " "," ","abc","def","ghi","jkl","mno" ,"pqrs" ,"tuv","wxyz"};

vector<string> solve(string s,int cur){
    //base
    if(cur>=s.size()){
       return {""};
    }

    int digit=s[cur]-'0';
    vector<string> rem=solve(s,cur+1);
    vector<string> ans;
    for(auto it:keypad[digit]){
       for(string st:rem){
          ans.push_back(it+st);
       }
    }
    return ans;
}

int main(){

   string s;
   cin>>s;
   for(auto it:solve(s,0)) cout<<it<<" ";
   cout<<endl;
   cout<<(solve(s,0).size());

}