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
const int shift = 1e5 + 5;
//===========================\\

int n, k;
vector<int>a, b;
int dp[105][(int)2e5 + 5];

int go(int i, int total){
    if(i == n)
        return total == 0? 0 : -oo;

    if(dp[i][total + shift] != -1)
        return dp[i][total + shift];

    int op1 = go(i + 1, total);
    int op2 = go(i + 1, total + a[i] - b[i] * k ) + a[i];

    return dp[i][total + shift] = max(op1, op2);
}

void solve()
{
    cin >> n >> k;
    a.resize(n + 1), b.resize(n + 1);

    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];

    memset(dp, -1, sizeof dp);
    int ans = go(0, 0);
    if(!ans)
        ans = -1;
    cout << ans;
}

signed main()
{
    Sonic File
    int T = 1; // cin >> T;
    while( T-- )
    {
        solve();
//         I HATE UVA
        if( T > 0 )
            cout << endl;
    }
    return 0;
}