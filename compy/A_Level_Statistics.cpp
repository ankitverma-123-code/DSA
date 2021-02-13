#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"


int main() {
	
	ll t;
	cin>>t;

	while(t--){

		ll n;
		cin>>n;

		ll a[n+1][3]={0};

		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=2;j++){
				cin>>a[i][j];
			}
		}

		ll flag=1;
		for(ll i=1;i<=n;i++){
			
				if( (a[i][1]-a[i-1][1]) < (a[i][2]-a[i-1][2])){
					flag = 0;
				}

				if( a[i][1]-a[i-1][1] < 0 ){
					flag = 0;
				}

				if( a[i][2] - a[i-1][2] < 0 ){
					flag = 0;
				}
		}

		if(flag ==1 ){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}

	}
	
	
	

	return 0;
}