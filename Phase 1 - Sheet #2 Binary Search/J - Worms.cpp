#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

//typedef tree<int ,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;//find_by_order(),order_of_key()

void fastIO(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

}

void fileIO(void) {

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif

}


#define int long long
#define ll  long long
#define ull  unsigned long long



void solve()
{
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=1;i<n;i++)
        v[i]+=v[i-1];
    int q; cin>>q;
    while(q--)
    {
        int target; cin>>target;
        int idx= lower_bound(v.begin(),v.end(),target)-v.begin();
        cout<<idx+1<<'\n';
    }
}
signed main() {
    fileIO();
    fastIO();
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
