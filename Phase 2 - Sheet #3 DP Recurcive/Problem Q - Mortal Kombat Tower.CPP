#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Ordered_Set = tree< T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using Ordered_Multiset = tree< T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// *find_by_order, order_of_key
using ll = long long;
using ld = long double;
#define F0R(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR(i,  a) F0R(i, 0, a)
#define endl "\n"
#define int long long
#define all(x) x.begin(), x.end()
#define mem(x, y) memset( x, y, sizeof x )
#define SetPre(n, x)  cout << fixed << setprecision(n) << x
#define Sonic ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
void File()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
#define File File();
#define yes cout << "YES"
#define no cout << "NO"
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int oo = 1e18 + 5;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
//===========================\\

int n, dp[N][2], vis[N][2], tc;
vector<int>v;

int go(int i, int who){
    if(i == n)
        return 0;

    if(vis[i][who] == tc)
        return dp[i][who];
    vis[i][who] = tc;

    int op1 = oo, op2 = oo;

    op1 = go(i + 1, who ^ 1) + (who == 0? v[i] : 0);
    if(i < n - 1)
        op2 = go(i + 2, who ^ 1) + (who == 0? v[i] + v[i + 1] : 0);

    return dp[i][who] = min(op1, op2);
}

void solve()
{
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];

    cout << go(0, 0);
}

signed main()
{
    Sonic File
    int T = 1; cin >> T;
    while( T-- )
    {
        tc++;
        solve();
//         I HATE UVA
        if( T > 0 )
            cout << endl;
    }
    return 0;
}