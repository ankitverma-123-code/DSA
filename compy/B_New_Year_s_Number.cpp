#include <bits/stdc++.h> 
#define int long long
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);cout.precision(dbl::max_digits10);
#define pb push_back
#define mod 1000000007ll //998244353ll
#define lld long double
#define mii unordered_map<int, int>
#define mci unordered_map<char, int>
#define msi map<string, int>
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second 
#define all(x) (x).begin(), (x).end()
#define forr(i,x,y) for(int i=x; i<y; i++)    
#define fill(a,b) memset(a, b, sizeof(a))
#define vi vector<int>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define setbits(x) __builtin_popcountll(x)
#define print2d(dp,n,m) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++)cout<<dp[i][j]<<" ";cout<<"\n";}
typedef std::numeric_limits< double > dbl;
using namespace std;

const long long N=200005, INF=2000000000000000000;
lld pi=3.1415926535897932;
 
int32_t main()
{
    IOS;
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int f=0;
        while(n>=2020){
          if(n%2021==0){
              f=1;
              cout<<"YES\n";
              break;
          }
          if(n%2020==0){
              f=1;
              cout<<"YES\n";
              break;
          }
          n-=2020;
        }
        
        if(!f)
        cout<<"NO\n";
        
    }
}