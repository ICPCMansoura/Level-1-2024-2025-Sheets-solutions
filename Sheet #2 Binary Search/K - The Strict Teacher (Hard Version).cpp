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
    int n,m,q;cin>>n>>m>>q;
    vector<int>v(m);
    for(int i=0;i<m;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    while(q--)
    {
        int x; cin>>x;
        if(x<v[0])
            cout<<v[0]-1<<'\n';
        else if(x>v[m-1])
            cout<<(n-v[m-1])<<'\n';
        else
        {
            int right= upper_bound(v.begin(),v.end(),x)-v.begin();
            cout<<(v[right]-v[right-1])/2<<'\n';
        }
    }
}
signed main() {
    fileIO();
    fastIO();
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
