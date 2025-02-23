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

string s, t;
int dp[205][205][205];
char open = '(', close = ')';
int n, m;
string ans;

// sum is number of openings with no closings
int go(int i, int j, int sum){
    if(i == n && j == m)
        return sum;

    if(dp[i][j][sum] != -1)
        return dp[i][j][sum];

    int op1 = oo, op2 = oo;
    // Add opening bracket '('
    if(s[i] == open || t[j] == open)
        op1 = go(i + (s[i] == open), j + (t[j] == open), sum + 1) + 1;

    // Add closing bracket ')'
    if(s[i] == close || t[j] == close)
        op2 = go(i + (s[i] == close), j + (t[j] == close), (sum? sum - 1 : 0)) + 1 + (sum == 0);

    return dp[i][j][sum] = min(op1, op2);
}

void build(int i, int j, int sum){
    if(i == n && j == m)
        return;

    int op1 = oo, op2 = oo;
    // Add opening bracket '('
    if(s[i] == open || t[j] == open)
        op1 = go(i + (s[i] == open), j + (t[j] == open), sum + 1) + 1;

    // Add closing bracket ')'
    if(s[i] == close || t[j] == close)
        op2 = go(i + (s[i] == close), j + (t[j] == close), (sum? sum - 1 : 0)) + 1 + (sum == 0);

    int optimal = min(op1, op2);
    if(optimal == op1){
        ans += open;
        build(i + (s[i] == open), j + (t[j] == open), sum + 1);
    }
    else{
        if(sum == 0)
            ans += "()";
        else
            ans += close;

        build(i + (s[i] == close), j + (t[j] == close), (sum? sum - 1 : 0));
    }
}

void solve()
{
    cin >> s >> t;
    n = s.size(), m = t.size();
    memset(dp, -1, sizeof dp);
    build(0, 0, 0);

    int opens = 0, closes = 0;
    for(char i : ans){
        if(i == open)
            opens++;
        else
            opens--;
    }

    while(opens-- > 0)
        ans += close;

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