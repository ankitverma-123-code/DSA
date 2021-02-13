#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    cout.precision(dbl::max_digits10);
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
#define forr(i, x, y) for (int i = x; i < y; i++)
#define fill(a, b) memset(a, b, sizeof(a))
#define vi vector<int>
#define ps(x, y) fixed << setprecision(y) << x
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define setbits(x) __builtin_popcountll(x)
#define print2d(dp, n, m)            \
    for (int i = 0; i <= n; i++)     \
    {                                \
        for (int j = 0; j <= m; j++) \
            cout << dp[i][j] << " "; \
        cout << "\n";                \
    }
typedef std::numeric_limits<double> dbl;
using namespace std;
const long long N = 200005, INF = 2000000000000000000;
lld pi = 3.1415926535897932;
int lcm(int a, int b)
{
    int g = __gcd(a, b);
    return a / g * b;
}
int power(int a, int b, int p = mod)
{
    if (a == 0)
        return 0;
    int res = 1;
    a %= p;
    while (b > 0)
    {
        if (b & 1)
            res = ((res % p) * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return res;
}

bool prime[10000007];
vector<int> primes;

void pre()
{
    fill(prime, true);
    prime[1] = 0;
    for (int p = 2; p * p <= 10000007; p++)
    {

        if (prime[p])
        {
            for (int i = p * p; i <= 10000007; i += p)
                prime[i] = false;
        }
    }
    for (int i = 1; i <= 10000007; i++)
    {
        if (prime[i])
        {
            primes.pb(i);
        }
    }
}

int factorization(int n)
{
    //vector<int> factors;
    int number = 1;
    int i = 0;
    int cnt;
    while (primes[i] * primes[i] <= n)
    {
        cnt = 0;
        if (n % primes[i] == 0)
        {
            //factors.push_back(primes[i]);
            while (n % primes[i] == 0)
            {
                n = n / primes[i];
                cnt++;
            }
            number = number * (cnt + 1);
        }
        i++;
    }

    if (n != 1)
    {
        //factors.push_back(n);
        number = number * (2);
    }
    return number;
}

bool isSorted(int a[])
{
    int x = a[0];
    for (int i = 0; i < 50; i++)
    {
        if (a[i] != 0 && a[i] > x)
        {
            x = a[i];
        }
        else if (a[i] != 0 && a[i] <= x)
        {
            return 0;
        }
    }
    return 1;
}

bool isPossible(int a[], int ind)
{
    int cnt = 0;
    for (int i = 1; i <= ind; i++)
    {
        if (a[i] <= a[ind] && a[i] != 0)
            cnt++;
        
    }
    return (cnt == ind);
}

int32_t main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[100] = {0};
        for (int i = 1; i <= n; i++)
            cin >> a[i];

    }
}