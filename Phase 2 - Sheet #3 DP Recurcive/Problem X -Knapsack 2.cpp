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
const int N = 5e6 + 5;
const int bestValue = 1e5;
//===========================\\

int n, wLimit;
struct item{
    int v, w;
};
vector<item>v;
int dp[105][(int)1e5 + 5];

int go(int i, int val){
    if(i == n)
        return (val == 0? 0 : oo);

    if(dp[i][val] != -1)
        return dp[i][val];

    int op1 = go(i + 1, val);
    int op2 = go(i + 1, val - v[i].v) + v[i].w;

    return dp[i][val] = min(op1, op2);
}

void solve()
{
    cin >> n >> wLimit;
    v.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i].w >> v[i].v;

    // 1e5 -> 0
    memset(dp, -1, sizeof dp);
    for(int i = bestValue; i >= 0; --i){
        if(go(0, i) <= wLimit)
            return void(cout << i);
    }
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