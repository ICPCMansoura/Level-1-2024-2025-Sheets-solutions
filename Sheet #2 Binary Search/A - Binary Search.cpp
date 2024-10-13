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
    int n,q; cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    while(q--)
    {
        int x; cin>>x;
        int l=0,r=n-1,mid,ans=-1;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(v[mid]==x)
            {
                ans=mid+1;
                break;
            }
            else if(v[mid]<x)
                l=mid+1;
            else
                r=mid-1;
        }
        cout<<ans<<'\n';
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
