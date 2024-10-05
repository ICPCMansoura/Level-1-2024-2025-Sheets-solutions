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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int>a(n), b(m);
        map<int, int>freq_a, freq_b;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i], freq_b[b[i]]++;
        int l = 0, r = 0, count = 0, ans = 0;
        while (r < m)
        {
            freq_a[a[r]]++;
            if (freq_b[a[r]] >= freq_a[a[r++]])
            {
                count++;
            }
        }
        while (r < n)
        {
            if (count >= k) ans++;
            freq_a[a[r]]++;
            if (freq_b[a[r]] >= freq_a[a[r]])count++;
            freq_a[a[l]]--;
            if (freq_a[a[l]] < freq_b[a[l]])count--;
            l++; r++;
        }
        if (count >= k) ans++;
        cout << ans << endl;
    }
}
