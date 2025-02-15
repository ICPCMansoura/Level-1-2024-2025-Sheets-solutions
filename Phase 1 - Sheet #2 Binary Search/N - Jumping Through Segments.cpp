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

int n;
vector<pair<int,int>>v;

bool can(int k)
{
    int leftPos=0,rightPos=0;
    for(int i=0;i<n;i++)
    {
        if(leftPos-k>v[i].second)
            return false;
        if(rightPos+k<v[i].first)
            return false;
        leftPos=max(v[i].first,leftPos-k);
        rightPos=min(v[i].second,rightPos+k);
    }
    return true;
}


void solve()
{
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        int l,r;cin>>l>>r;
        v[i]={l,r};
    }
    int l=0,r=1e9,mid,ans=0;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(can(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans<<'\n';
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
