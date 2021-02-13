#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);



int a[1000001];

void SieveOfEratosthenes() 
{ 
	bool prime[1000001]; 
	memset(prime, true, sizeof(prime)); 

	for (int p=2; p*p<=1000000; p++) 
	{ 
		
		if (prime[p] == true) 
		{ 
			for (int i=p*p; i<=1000000; i += p) 
				prime[i] = false; 
		} 
	} 

	memset(a, 0, sizeof(a)); 
	for(int p=2; p<=1000000; p++) 
        if (prime[p]) {
            a[p]=a[p-1]+1;
        }
        else a[p]=a[p-1];
}
 
int32_t main()
{
    IOS;
    SieveOfEratosthenes();
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int k=a[x];
        //deb(k);
        if(k>y)
            cout<<"Divyam"<<endl;
        else
            cout <<"Chef"<<endl;
    }
}