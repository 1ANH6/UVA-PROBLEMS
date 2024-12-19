#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int PIK = 1e9;
int dp[207][11007];
vector<pair<int, int>> v(107);
int m, n;

int f(int pos, int res)
{
    if(pos == n && res == 0)
        return 0;
    if(res <= 0)
        return 0;
    if(dp[pos][res] != -1e9)
        return dp[pos][res];
    if(v[pos].first <= res)
        dp[pos][res] = max(f(pos+1, res), f(pos+1, res-v[pos].first) + v[pos].second);
    else
        dp[pos][res] = f(pos+1, res);
    return dp[pos][res];
}

void R()
{
    while(cin >> m >> n)
    {
        for(int i = 0; i <= 200; i++)
            for(int j = 0; j <= 11000; j++)
                dp[i][j]= -1e9;
        for(int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;
        int x = f(0, m+200);
        int may = -1e9;
        for(int i = 0; i <= m; i++)
            may = max(may, f(0, i));
        for(int i = 2001; i <= m+200; i++)
            may = max(may, f(0, i));
        cout << may << "\n";
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
