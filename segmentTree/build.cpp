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

void updateintree(int* a,int* tree,int start,int end,int nodeidx,int idx,int value){

if(start==end){
    a[idx]=value;
    tree[nodeidx]=value;
    return;
}
    int mid =(start+end)/2;

    if(idx>mid){
        updateintree(a,tree,mid+1,end,2*nodeidx+1,idx,value);
    }
    else updateintree(a,tree,start,mid,2*nodeidx,idx,value);

    tree[nodeidx]=tree[2*nodeidx]+tree[2*nodeidx+1];
}


int main(){
    int a[]={1,2,3,4,5};
    int* tree=new int[10];

    buildTree(a,tree,0,4,1);
    updateintree(a,tree,0,4,1,2,10);
    for(int i=1;i<=9;i++)
     cout<<tree[i]<<endl;

     delete [] tree;
}