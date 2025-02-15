#include <bits/stdc++.h>
using namespace std;
const int N=262144+5;
#define int long long
const int MOD = 1e9 + 7;
const int MAX_A = 1e7;

vector<int> sieve(MAX_A + 1);

void proc() {
    for (int i = 2; i <= MAX_A; i++) {
        if (sieve[i] == 0) { 
            for (int j = i; j <= MAX_A; j += i) {
                sieve[j] = i;
            }
        }
    }
}
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1,a,b;//cin>>t;
    while(t--){
        int n;cin>>n;
        int ans=1;
        vector<int>arr(n),vis(MAX_A+5,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        proc();
        
        for(int i=0;i<n;i++){
            int num=arr[i];
            while(num>1){
                  int prm = sieve[num];
                    int pw = 0;
                    while (num % prm == 0) {
                    num /= prm;
                    pw++;
                }
                vis[prm]+=pw;
            }
        }
        for(int i=2;i<=MAX_A;i++){
            if(vis[i]>0){
                ans*=(vis[i]+1)%MOD;
                   ans%=MOD;
            }
        }
        cout<<ans;
        
    }
    return 0;
 
}