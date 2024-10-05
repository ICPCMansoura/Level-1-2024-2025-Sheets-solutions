#include <iostream>
#include<istream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <stack>
#include <climits>
#include<map>
#include<string>
#include<set>
#include <cstring>
#include<unordered_map>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#define ll   long long
#define MOD 1000000007
#define endl "\n"
using namespace std;
void fast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(nullptr);
}
ll  gcd(ll  a, ll  b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
signed main() {
    fast();
    //freopen("paintbarn.in", "r", stdin);
    //freopen("paintbarn.out", "w", stdout);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        vector<ll>prfx(n + 1);
        for (int i = 1; i < n; i++)
        {
            prfx[i] += prfx[i - 1] + (s[i - 1] - '0');
        }
        ll l = 1, r = 1 , ans = 0 , sum = 0;
         map<ll, ll>freq;
         freq[0] = 1;
         for (int idx = 0; idx < n; idx++)
         {
             int num = s[idx] - '0' - 1;
             sum += num;
             ans += freq[sum];
             freq[sum]++;
         }
        cout << ans <<endl;
    }
}
