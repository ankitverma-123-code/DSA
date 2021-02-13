#include <bits/stdc++.h>
using namespace std;
#define m1 1000000007
#define ll long long
#define vi vector<int>
#define mid(l, r) (l + (r - l) / 2)
#define loop(i, a, b) for(int i = (a); i<= (b); i++)
#define loopneg(i, a, b) for(int i = (a); i>= (b); i--)
#define arint(n) int ar[n]

void input(vector<int> &ar, int n);
void output(vector<int> ar);

int getIndex(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);
    if (it != v.end()) 
    {
        int index = it - v.begin();
        return index;
    }
    else {
        return -1;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;
	while(t--)
	{
	    ll n, count = 0; cin>>n;

        vector<int> a; input(a, n);
        vector<int> pos(n); 
            loop(i, 0, n-1)
             pos[i] = i;
        vector<int> l;
         input(l, n);

        vector<int> b(n); loop(i, 0, n-1) b[i] = a[i];
        sort(b.begin(), b.end());

        loop(j, 1, n-1)
        {
            int index = getIndex(a, b[j]);
            int p = pos[getIndex(a, b[j-1])];
            int c = index;

            while(c<= p)
            {
                c += l[index];
                pos[index] = c;
                count ++;
            }
        }
        cout<<count<<endl;
	}
	return 0;
}


void input(vector<int> &ar, int n){
    int ele;
    for(int i = 0; i< n; i++){cin>>ele; ar.push_back(ele);}
}
void output(vector<int> ar){
    for(auto ele: ar)cout<<ele<<" ";cout<<endl;
}