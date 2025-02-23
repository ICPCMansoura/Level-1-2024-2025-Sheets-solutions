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
        freopen("feast.in", "r", stdin);
        freopen("feast.out", "w", stdout);
    #endif
}
#define File File();
#define yes cout << "YES"
#define no cout << "NO"
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int oo = 1e18 + 5;
const int MOD = 1e9 + 7;
const int N = 5e6 + 5;
//===========================\\

int t, a, b, dp[N][2];

int go(int fullness, int drink){
    if(fullness > t)
        return -oo;

    if(dp[fullness][drink] != -1)
        return dp[fullness][drink];

    int op1 = fullness;
    int op2 = go(fullness + a, drink);
    int op3 = go(fullness + b, drink);
    int op4 = -oo;
    if(drink == 0)
        op4 = go(fullness / 2, 1);

    return dp[fullness][drink] = max({op1, op2, op3, op4});
}

void solve()
{
    cin >> t >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << go(0, 0);
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