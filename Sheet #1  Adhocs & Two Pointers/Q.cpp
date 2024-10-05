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
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = 0;
    int count_zeros = 0, MaxRange = 0, Max_l = 0, Max_r = 0;

    while (r < n)
    {
        if (a[r] == 0)
            count_zeros++;
        while (count_zeros > k)
        {
            count_zeros -= a[l] == 0;
            l++;
        }
        if ((r - l + 1) >= MaxRange)
        {
            MaxRange = r - l + 1;
            Max_l = l; Max_r = r;
        }
        r++;
    }
    cout << MaxRange << '\n';
    for (int i = 0; i < n; i++)
    {
        if (i >= Max_l && i <= Max_r)
            cout << 1 << ' ';
        else
            cout << a[i] << ' ';
    }
}
