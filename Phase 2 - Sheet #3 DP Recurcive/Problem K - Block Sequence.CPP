#include <bits/stdc++.h>

using namespace std;

#define Sonic ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long

const int mod = 1e9 + 7;
int n;
vector<int> nums;
int dp[200005][2];

int go (int idx, int keep) {
    if (idx > n)
        return LLONG_MAX;

    if (idx == n)
        return 0;

    if (dp[idx][keep] != -1)
        return dp[idx][keep];

    int ch1 = go (idx + nums[idx] + 1, 1);
    int ch2 = go (idx + 1, 0) + 1;

    return dp[idx][keep] = min(ch1, ch2);
}

void palmer() {
    cin >> n;
    nums.assign(n, 0);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << go(0, 1);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Sonic
    int t = 1; cin >> t;
    while (t--){
        palmer();
        if (t > 0)
            cout << "\n";
    }
}