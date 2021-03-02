#include <bits/stdc++.h>
using namespace std;
void buildTree(int* a,int* tree,int start,int end,int nodeidx){
    if(start==end){
        tree[nodeidx]=a[start];
        return;
    }

    int mid=(start+end)/2;

    buildTree(a,tree,start,mid,2*nodeidx);
    buildTree(a,tree,mid+1,end,2*nodeidx+1);

    tree[nodeidx]=tree[2*nodeidx]+tree[2*nodeidx+1];
}


int main(){
    int a[]={1,2,3,4,5,6,7,8,9};
    int* tree=new int[18];

    buildTree(a,tree,0,8,1);
    for(int i=1;i<=15;i++)
     cout<<tree[i]<<endl;

     delete [] tree;
}