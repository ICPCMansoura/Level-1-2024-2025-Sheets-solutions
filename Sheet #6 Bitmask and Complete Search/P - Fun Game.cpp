#include <bits/stdc++.h>

using namespace std;
# define  mod  1000000007
#define ll long long
#define ld long double
#define PI 3.141592654
#define endl "\n"
#define Endl "\n"
#ifdef LOCAL
#else
#define debug(...) 42
#endif

bool checkbit (int n,int bit) {
    return n & (1<<bit);
}
int turnon (int n,int bit) {
     n |= (1<<bit);
    return n;
}
int turnoff (int n,int bit) {
    n &= (~(1<<bit));
    return n;
}
int toggle (int n,int bit) {
    n ^= (1<<bit);
    return n;
}
bool ispoweroftwo (int n) {
    return __builtin_popcount(n)==1;
}
vector<ll> baserepresentation (ll n,ll base) {
    vector<ll> res;
    while (n) {
        res.push_back(n%base);
        n/=base;
    }
    reverse(res.begin(),res.end());
    return res;
}
ll exp(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2==1) {
            result = (result * (base)) ;
        }
        base = (base * (base)) ;
        exp = exp  / 2;
    }
    return result;
}
ll decimalrepresentation(string s,int base) {
    ll res=0;
    for (ll i=0;i<s.length();i++) {
        res+= (s[i]-'0') * exp(base,i);
    }
    return res;
}


int main() {
    cout << fixed << setprecision(9);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--) {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        bool f=1;
        for(int i=0;i<n;i++) {
            if(t[i]=='1' and s[i]!='1') {
                f=0;
                break;
            }
            if(s[i]=='1')break;
        }
        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}