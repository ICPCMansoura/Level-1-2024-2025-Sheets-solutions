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
    int n,a,b;cin>>n>>a>>b;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int>sorted=v;
    sort(sorted.begin(),sorted.end());
    for(int i=0;i<n;i++)
    {
        int r= lower_bound(sorted.begin(),sorted.end(),v[i]+b)-sorted.begin()-1;
        int l= lower_bound(sorted.begin(),sorted.end(),v[i]+a)-sorted.begin();
        cout<<r-l+1<<" ";
        r= upper_bound(sorted.begin(),sorted.end(),v[i]-a)-sorted.begin()-1;
        l=upper_bound(sorted.begin(),sorted.end(),v[i]-b)-sorted.begin();
        cout<<r-l+1<<'\n';
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
