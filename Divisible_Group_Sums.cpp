#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int PIK = 1e9;
ll dp[207][27][17];
vector<int> v(207);
int n, cnt = 1;
ll d;

ll f(int pos, ll mod, int res)
{
    if(pos == n || !res)
        return 0;
    if(dp[pos][mod][res] != -1)
        return dp[pos][mod][res];
    dp[pos][mod][res] = f(pos+1, mod, res) + f(pos+1, (mod+v[pos]+d*1000000000) % d, res-1);
    if(res == 1 && (mod+v[pos]) % d == 0)
        dp[pos][mod][res]++;
    return dp[pos][mod][res];
}

void R()
{
    int q; 
    while(cin >> n >> q)
    {
        if(!n && !q)
            return;
        cout << "SET " << cnt << ":\n";
        for(int i = 0; i < n; i++)
        cin >> v[i];
        int m; 
        for(int l = 0; l < q; l++)
        {
            cout << "QUERY " << l+1 << ": "; 
            for(int i = 0; i < n; i++)
                for(int j = 0; j <= 20; j++)
                    for(int k = 0; k <= 10; k++)
                        dp[i][j][k] = -1;
            cin >> d >> m;
            cout << f(0, 0, m) << "\n";
        }
        cnt++;
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
