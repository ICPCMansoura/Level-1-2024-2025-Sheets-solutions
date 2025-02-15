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
    int n, x, y;
    cin >> n >> x >> y;
    int lcm = x / __gcd(x, y) * y;
    int X = (n / x - n / lcm);
    int Y = (n / y - n / lcm);
    int sumY = Y * (Y + 1) / 2;
    int sumX = n * (n + 1) / 2 - (n - X) * (n - X + 1) / 2;
    cout << sumX - sumY << '\n';
}

signed main() {
    fileIO();
    fastIO();
    int numOfTests = 1;
    cin >> numOfTests;
    for (int testCase = 1; testCase <= numOfTests; testCase++)
        solve(testCase);
    return 0;
}