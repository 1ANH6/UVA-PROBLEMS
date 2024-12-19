#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int PIK = 1e9;
const int mod = 1e6;
ll dp[107][107];

ll f(int n, int m)
{
    if(m == 1)
        return 1;
    if(dp[n][m] != -1)
        return dp[n][m];
    ll cnt = 0;
    for(int i = n; i >= 0; i--)
    {
        cnt += f(i, m-1);
        cnt %= mod;
    }
    dp[n][m] = cnt;
    return dp[n][m];
}

void R()
{
    int n, m;
    while(cin >> n >> m)
    {
        if(!n && !m)
            break;
        memset(dp, -1, sizeof(dp));
        cout << f(n, m) << "\n";
    }
}   
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1; //cin >> t;
    while(t--)
        R();
    return 0;
}
