#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


void solve(int testCase) {
    // A % B ??
    string A;
    cin >> A;
    int B;
    cin >> B;

    int ans = 0, tenPowerX = 1;
    for (int i = A.size() - 1; i >= 0; --i) {
        int digit = (A[i] - '0') % B;
        ans += (digit * tenPowerX) % B;
        ans %= B;
        tenPowerX *= 10 % B;
        tenPowerX %= B;
    }
    cout << ans << '\n';
}


signed main() {
    fileIO();
    //fastIO();
    int numOfTests = 1;
    //cin >> numOfTests;
    for (int testCase = 1; testCase <= numOfTests; testCase++)
        solve(testCase);
    return 0;
}