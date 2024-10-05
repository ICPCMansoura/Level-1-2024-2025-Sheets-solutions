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
int a[505][505], b[505][505];
signed main() {
    fast();
    //freopen("paintbarn.in", "r", stdin);
    //freopen("paintbarn.out", "w", stdout);
    int n; cin >> n;
    vector<int>nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    ll l = 0, r = 0, total = 0;
    while (r < n)
    {
        if (l == r)
            total++;
        else
        {
            if (nums[r - 1] - nums[r] == nums[l] - nums[l + 1])
                total += (r - l + 1);
            else
                l = r - 1, total += 2;
        }
        r++;
    }
    cout << total;
}
