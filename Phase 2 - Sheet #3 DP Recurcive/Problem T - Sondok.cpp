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
const int MOD = 1e8;
const int N = 1e6 + 6;
//===========================\\

int n1, n2, k1, k2, dp[105][105][15][15];

int go(int nn1, int nn2, int limit1, int limit2){
    if(nn1 > n1 || nn2 > n2 || limit1 > k1 || limit2 > k2)
        return 0;

    if(nn1 == n1 && nn2 == n2)
        return 1;

    if(dp[nn1][nn2][limit1][limit2] != -1)
        return dp[nn1][nn2][limit1][limit2];

    int op1 = go(nn1 + 1, nn2, limit1 + 1, 0);
    int op2 = go(nn1, nn2 + 1, 0, limit2 + 1);

    return dp[nn1][nn2][limit1][limit2] = (op1 % MOD + op2 % MOD) % MOD;
}

void solve()
{
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof dp);
    cout << go(0, 0, 0, 0);
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