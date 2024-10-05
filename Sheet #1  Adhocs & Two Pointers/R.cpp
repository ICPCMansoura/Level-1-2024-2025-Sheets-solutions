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
        string s; cin >> s;
        int n = s.size(), ans = 0;
        for (int k = 1; k <= n; k++)
        {
            vector<ll>prfx = { 0 }, idx;
            for (int i = 0; i + k < n; i++)
            {
                if (s[i] == '?' || s[i + k] == '?' || s[i] == s[i + k])
                    prfx.push_back(i);
            }
            idx = prfx;
            for (int i = 1; i < prfx.size(); i++)
                prfx[i] += prfx[i - 1];
            for (int i = k; i < prfx.size(); i++)
            {
                ll end = idx[i] * (idx[i] + 1) / 2;
                ll start = (idx[i] - k) * ((idx[i] - k) + 1) / 2;
                if (prfx[i] - prfx[i - k] == end - start)
                    ans = k * 2;
            }
        }
        cout << ans << '\n';
    }
}
