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

int n,s,cost;
vector<int>v;

bool can(int k)
{
    cost=0;
    vector<int>new_price(n);
    for(int i=0;i<n;i++)
    {
        new_price[i]=v[i]+k*(i+1);
    }
    sort(new_price.begin(),new_price.end());
    for(int i=0;i<k;i++)
        cost+=new_price[i];
    if(cost<=s)return true;
    else return false;
}

void solve()
{
    cin>>n>>s;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int l=0,r=n,mid,ans=0,final_cost=0;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(can(mid))
        {
            ans=mid;
            final_cost=cost;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans<<" "<<final_cost<<'\n';
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
