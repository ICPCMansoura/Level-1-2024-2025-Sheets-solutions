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

int n, l, r;
int colors[200001];
signed main() {
    fast();
    //freopen("paintbarn.in", "r", stdin);
    //freopen("paintbarn.out", "w", stdout);
    int t; cin >> t;
    while (t--)
    {
        cin >> n >> l >> r;
        map<int, int>left_colors, right_colors;
        for (int i = 1; i <= n; i++) {
            cin >> colors[i];
            if (i <= l)
                left_colors[colors[i]]++;
            else
                right_colors[colors[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            int mini = min(left_colors[i], right_colors[i]);
            left_colors[i] -= mini;
            right_colors[i] -= mini;
            l -= mini;
            r -= mini;
        }
        if (l < r) {
            swap(left_colors, right_colors);
            swap(l, r);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int extra = l - r;
            int Halfcolor = left_colors[i] / 2;
            int turn = min(Halfcolor * 2, extra);
            ans += turn / 2;
            l -= turn;
        }
        ans += (l - r) / 2 + (l + r) / 2;
        cout << ans << endl;
    }
}
