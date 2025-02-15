#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_A = 1000;
void solve() {
    int n;
    cin >> n;
    int size = 2 * n;
    vector<int> od,ev;
    int x;
    for(int i=0;i<size;i++){
        cin >> x;
        if(x % 2 == 0) ev.push_back(i+1);
        else od.push_back(i+1);
    }
    int cur=0;
    for(int i=0;i<od.size();i+=2){
        if(i+1<od.size() && cur<n-1){
            cur++;
            cout<<od[i]<<" "<<od[i+1]<<"\n";
        }
        //i++;
    }
    for(int i=0;i<ev.size();i+=2){
        if(i+1<ev.size() && cur<n-1){
            cur++;
            cout<<ev[i]<<" "<<ev[i+1]<<"\n";
        }
        //i++;
    }
}
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
