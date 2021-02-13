#include <bits/stdc++.h>
using namespace std;

bool solve(int a[],int n, int i, int sum, bool included = false)
{
    if (i==n)
        return (sum == 0 && included);
    return solve(a, i + 1, sum + a[i], true) +solve(a, i + 1, sum, included);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin>>a[i];
        if (solve(a,n,0,0))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        
    }

    return 0;
}