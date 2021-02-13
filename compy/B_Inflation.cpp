#include <bits/stdc++.h> 

using namespace std;
void sum(int a,int b,int *c,int *d){
   
    *c=a+b;
    *d=a-b;
}

 
int main()
{
  int x=2,y=3,c,d;
  sum(x,y,&c,&d);

  cout<<c<<" "<<d;
   return 0;
}