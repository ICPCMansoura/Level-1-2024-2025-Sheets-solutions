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
    fast;
    //freopen("paintbarn.in", "r", stdin);
    //freopen("paintbarn.out", "w", stdout);
    int t = 1; cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<vector<ll>>prfx(1001, vector<ll>(1001));
        for (int i = 0; i < n; i++)
        {
            ll h, w;
            cin >> h >> w;
            prfx[h][w] += h * w;
        }
        for (int i = 1; i <= 1000; i++)
        {
            for (int j = 1; j <= 1000; j++)
            {
                prfx[i][j] += prfx[i][j - 1];
            }
        }
        for (int i = 1; i <= 1000; i++)
        {
            for (int j = 1; j <= 1000; j++)
            {
                prfx[i][j] += prfx[i - 1][j];
            }
        }
        while (q--)
        {
            ll h1, w1, h2, w2;
            cin >> h1 >> w1 >> h2 >> w2;
            cout << prfx[h2 - 1][w2 - 1] - prfx[h2 - 1][w1] - prfx[h1][w2 - 1] + prfx[h1][w1] << '\n';
        }
    }

}
