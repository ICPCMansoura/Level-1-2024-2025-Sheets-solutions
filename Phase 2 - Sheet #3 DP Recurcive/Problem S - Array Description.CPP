#include <bits/stdc++.h>

using namespace std;

using namespace std;
#define int long long
int const N =  1e5 + 5;
int n,m;
int mod = 1e9 + 7;
int dp[N][101];
vector<int>a;

int go(int i, int last) {
    if (i == n) return 1;
    if (last != 0 && a[i] != 0 && abs(last - a[i]) > 1) return 0;
    if (dp[i][last] != -1) return dp[i][last];
    if (a[i] != 0) return dp[i][last] = go(i + 1, a[i]);
    int ch1 = last > 0 && last <= m ? go(i + 1, last) : 0;
    int ch2 = last - 1 > 0 ? go(i + 1, last - 1) : 0;
    int ch3 = last + 1 <= m ? go(i + 1, last + 1) : 0;
    return dp[i][last] = (ch1 + ch2 + ch3) % mod;
}
void SOLVE() {
    cin >> n >> m;
    memset(dp,-1,sizeof (dp));
    a.resize(n);
    cin >> a;
    int ans = 0;
    if(a[0] == 0){
        for (int i = 1; i <=m ; ++i) {
            a[0] = i;
            ans+= go(1 , a[0])%mod;
        }
    }else {
        ans = go(1,a[0]);
    }
    cout << ans%mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1 ;
    //cin >> t;
    while (t--) {
        SOLVE();
    }
    return 0;
}
